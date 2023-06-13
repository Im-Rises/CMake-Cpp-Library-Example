#define CL_HPP_TARGET_OPENCL_VERSION 300
#include <CL/opencl.hpp>

#include <cstdio>
#include <cstdlib>
#include <sys/stat.h>

#define PRINT_MATRIX_THRESHOLD 30

const char* programSource = "kernel void floydWarshall(global int *a, int k, int n) {\n"
                            "    int i = get_global_id(0);\n"
                            "    int j = get_global_id(1);\n"
                            "    int ij = i*n+j;\n"
                            "    int ik = i*n+k;\n"
                            "    int kj = k*n+j;\n"
                            "    if (a[ik] + a[kj] < a[ij]) {\n"
                            "        a[ij] = a[ik] + a[kj];\n"
                            "    }\n"
                            "}\n\0";

int* generateTestMatrix(int n) {
    /*
     * Generate a test matrix looks like this (for n = 4):
     *   0    1  n+1  n+1
     * n+1    0    1  n+1
     * n+1  n+1    0    1
     *   1  n+1  n+1    0
     *
     *   n+1 aka INF (infinity)
     */
    int* matrix = (int*)malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                matrix[i * n + j] = 0;
            else if (i == j - 1)
                matrix[i * n + j] = 1;
            else
                matrix[i * n + j] = n + 1;
        }
    }
    matrix[(n - 1) * n] = 1;
    return matrix;
}

int countDigit(long long n) {
    if (n / 10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

void printMatrix(int* matrix, int n) {
    if (n > PRINT_MATRIX_THRESHOLD)
    {
        printf("Matrix is too large to printed completely.\n");
        printf("- First row: ");
        for (int i = 0; i < n; i++)
        {
            if (matrix[i] == n + 1)
                printf("%*s ", countDigit(n + 1), "INF");
            else
                printf("%*d ", countDigit(n + 1), matrix[i]);
        }
        printf("\n");

        printf("- Last row: ");
        for (int i = (n - 1) * n; i < n * n; i++)
        {
            if (matrix[i] == n + 1)
                printf("%*s ", countDigit(n + 1), "INF");
            else
                printf("%*d ", countDigit(n + 1), matrix[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i * n + j] == n + 1)
                    printf("%4s", "INF");
                else
                    printf("%4d", matrix[i * n + j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

char* readProgramFile(const char* filename) {
    FILE* fp;
    char* source;
    int sz = 0;
    struct stat status;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    if (stat(filename, &status) == 0)
        sz = (int)status.st_size;

    source = (char*)malloc(sz + 1);
    fread(source, sz, 1, fp);
    source[sz] = '\0';
    return source;
}

int main(int argc, char* argv[]) {
    printf("|-----Floyd-Warshall parallel OpenCL algorithm-----|\n\n");

    // Check the command line arguments
    cl_int n = 10;

    // STEP 0: Init variables
    const char* programFunction = "floydWarshall";
    cl_int status = 0;
    cl::Platform platform;
    cl::Device device;
    cl::Context context;
    cl::CommandQueue cmdQueue;
    cl::Program program;
    char platformName[1000];

    // STEP 1: Discover and initialize the platforms
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    platform = platforms[0];
    platform.getInfo(CL_PLATFORM_NAME, &platformName);
    printf("Name of platform: %s\n", platformName);

    // STEP 2: Discover and initialize the devices
    std::vector<cl::Device> devices;
    platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
    for (int i = 0; i < devices.size(); i++)
    {
        devices[i].getInfo(CL_DEVICE_NAME, &platformName);
        printf("Name of device %d: %s\n", i, platformName);
    }

    // STEP 3: Create a context
    context = cl::Context(devices, NULL, NULL, NULL, &status);

    // STEP 4: Create a command queue
    cmdQueue = cl::CommandQueue(context, devices[0], 0, &status);

    // STEP 5: Create program object
    if (programSource == NULL)
    {
        perror("Cannot read OpenCL file.\n");
        return 1;
    }
    program = cl::Program(context, programSource, true, &status);

    // STEP 6: Build program
    status = program.build(devices);
    if (status != CL_SUCCESS)
    {
        printf("Error in building program.\n");
        std::string buildLog = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(devices[0]);
        printf("%s \n", buildLog.c_str());
        exit(1);
    }

    // STEP 7: Create kernel object
    cl::Kernel kernel(program, programFunction, &status);

    // STEP 8: Create buffers
    int* A = generateTestMatrix(n);
    cl::Buffer A_buf(context, CL_MEM_READ_WRITE, n * n * sizeof(int), NULL, &status);
    status = cmdQueue.enqueueWriteBuffer(A_buf, CL_TRUE, 0, n * n * sizeof(int), A, NULL, NULL);

    // STEP 9: Configure work-item structure
    cl::NDRange globalWorkSize(n, n);
    printf("Global work size: %d, %d\n\n", (int)globalWorkSize[0], (int)globalWorkSize[1]);

    // STEP 10: Print initial matrix
    printf("Initial matrix:\n");
    printMatrix(A, n);

    // STEP 11: Set kernel arguments
    status = kernel.setArg(0, A_buf);
    status = kernel.setArg(2, n);

    // STEP 12: Enqueue kernel for execution and execute for each k = 0, 1, ..., n - 1
    for (int k = 0; k < n; k++)
    {
        status = kernel.setArg(1, k);
        status = cmdQueue.enqueueNDRangeKernel(kernel, cl::NullRange, globalWorkSize, cl::NullRange, NULL, NULL);
    }

    // STEP 13: Read the output buffer back to the host
    status = cmdQueue.enqueueReadBuffer(A_buf, CL_TRUE, 0, n * n * sizeof(int), A, NULL, NULL);

    // STEP 14: Display the result
    printf("Result:\n");
    printMatrix(A, n);

    // STEP 15: Release OpenCL resources
    free(A);

    return 0;

}

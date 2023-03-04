/*
 * This file is an example of using OpenCL to implement Floyd-Warshall algorithm.
 * The algorithm is implemented in OpenCL kernel function in program.cl file.
 * It is one of my project, which you can find details about in the GitHub link below:
 * https://github.com/Im-Rises/cFloydWarshallParallel/tree/main
 */

#define CL_TARGET_OPENCL_VERSION 300
#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

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
    //    if (argc != 2)
    //    {
    //        printf("Usage: %s <n value>\n", argv[0]);
    //        return 1;
    //    }
    //    cl_int n = atoi(argv[1]);

    // Read from command line
    cl_int n = 10;
    //    scanf("%d", &n);

    // STEP 0: Init variables
    const char* programFunction = "floydWarshall";
    cl_int status = 0;
    cl_uint numPlatforms = 0;
    cl_platform_id* platforms = NULL;
    cl_uint numDevices = 0;
    cl_device_id* devices = NULL;
    cl_context context = NULL;
    cl_command_queue cmdQueue = NULL;
    cl_kernel kernel = NULL;
    char platformName[1000];

    // STEP 1: Discover and initialize the platforms
    status = clGetPlatformIDs(0, NULL, &numPlatforms);
    printf("Number of platforms = %d\n", numPlatforms);
    platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
    status = clGetPlatformIDs(numPlatforms, platforms, NULL);
    clGetPlatformInfo(*platforms, CL_PLATFORM_NAME, sizeof(platformName), platformName, NULL);
    printf("Name of platform : %s\n", platformName);

    // STEP 2: Discover and initialize the devices
    status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
    printf("Number of devices = %d\n", (int)numDevices);
    devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
    status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, numDevices, devices, NULL);
    for (int i = 0; i < numDevices; i++)
    {
        clGetDeviceInfo(devices[i], CL_DEVICE_NAME, sizeof(platformName), platformName, NULL);
        printf("Name of device %d: %s\n", i, platformName);
    }

    // STEP 3: Create a context
    context = clCreateContext(NULL, numDevices, devices, NULL, NULL, &status);

    // STEP 4: Create a command queue
    //    cmdQueue = clCreateCommandQueue(context, devices[0], 0, &status);
    cmdQueue = clCreateCommandQueueWithProperties(context, devices[0], 0, &status);

    // STEP 5: Create program object
    if (programSource == NULL)
    {
        perror("Cannot read OpenCL file.\n");
        return 1;
    }
    cl_program program = clCreateProgramWithSource(context, 1, (const char**)&programSource, NULL, &status);

    // STEP 6: Build program
    status = clBuildProgram(program, numDevices, devices, NULL, NULL, NULL);
    if (status != CL_SUCCESS)
    {
        printf("Error in building program.\n");
        size_t len;
        char buffer[2048];
        clGetProgramBuildInfo(program, devices[0], CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s \n", buffer);
        exit(1);
    }

    // STEP 7: Create kernel object
    kernel = clCreateKernel(program, programFunction, &status);

    // STEP 8: Create buffers
    int* A = generateTestMatrix(n);
    cl_mem A_buf = clCreateBuffer(context, CL_MEM_READ_WRITE, n * n * sizeof(int), NULL, &status);
    status = clEnqueueWriteBuffer(cmdQueue, A_buf, CL_TRUE, 0, n * n * sizeof(int), A, 0, NULL, NULL);

    // STEP 9: Configure work-item structure
    size_t globalWorkSize[2] = { (size_t)n, (size_t)n };
    printf("Global work size: %d, %d\n\n", (int)globalWorkSize[0], (int)globalWorkSize[1]);

    // STEP 10: Print initial matrix
    printf("Initial matrix:\n");
    printMatrix(A, n);

    // STEP 11: Set kernel arguments
    status = clSetKernelArg(kernel, 0, sizeof(cl_mem), &A_buf);
    status = clSetKernelArg(kernel, 2, sizeof(cl_int), &n);

    // STEP 12: Enqueue kernel for execution and execute for each k = 0, 1, ..., n - 1
    for (int k = 0; k < n; k++)
    {
        status = clSetKernelArg(kernel, 1, sizeof(int), &k);
        status = clEnqueueNDRangeKernel(cmdQueue, kernel, 2, NULL, globalWorkSize, NULL, 0, NULL, NULL);
    }

    // STEP 13: Read the output buffer back to the host
    status = clEnqueueReadBuffer(cmdQueue, A_buf, CL_TRUE, 0, n * n * sizeof(int), A, 0, NULL, NULL);

    // STEP 14: Display the result
    printf("Result:\n");
    printMatrix(A, n);

    // STEP 15: Release OpenCL resources
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQueue);
    clReleaseContext(context);
    clReleaseMemObject(A_buf);
    free(A);
    free(devices);
    free(platforms);

    return 0;
}

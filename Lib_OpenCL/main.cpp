#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#include <cstdio>
#endif

int main(int argc, char** argv) {
    cl_int err;
    cl_uint numPlatforms;
    cl_platform_id platform = NULL;
    err = clGetPlatformIDs(0, NULL, &numPlatforms);
    if (err != CL_SUCCESS || numPlatforms <= 0)
    {
        printf("Failed to find any OpenCL platforms.");
        return -1;
    }

    //For clarity, choose the first available platform.
    if (clGetPlatformIDs(1, &platform, NULL) != CL_SUCCESS)
    {
        printf("Failed to find any OpenCL platforms.");
        return -1;
    }

    cl_uint numDevices = 0;
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
    if (err != CL_SUCCESS || numDevices <= 0)
    {
        printf("Failed to find any OpenCL devices.");
        return -1;
    }

    //Choose the first available device.
    cl_device_id device;
    if (clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 1, &device, NULL) != CL_SUCCESS)
    {
        printf("Failed to find any OpenCL devices.");
        return -1;
    }

    cl_context context = clCreateContext(0, 1, &device, NULL, NULL, &err);
    if (err != CL_SUCCESS)
    {
        printf("Failed to create an OpenCL context.");
        return -1;
    }

    cl_command_queue queue = clCreateCommandQueue(context, device, 0, &err);
    if (err != CL_SUCCESS)
    {
        printf("Failed to create an OpenCL command queue.");
        return -1;
    }

    clReleaseCommandQueue(queue);

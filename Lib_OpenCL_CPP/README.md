# OpenCL_CPP

Version: OpenCL 3.0

OpenCL is a framework for writing programs that execute across heterogeneous platforms consisting of CPUs, GPUs, DSPs,
FPGAs, and other processors or hardware accelerators.

This version use the same API example as the C version, but with the C++ bindings.

> **Warning**  
> For unknown reasons, the OpenCL library is not working on macOS.
> If you have any idea why, please let me know.

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

OpenCL available on all platforms, but the setup is different.

#### Windows

For windows, you need to download the OpenCL SDK from the OpenCL-SDK github repository.
<https://github.com/KhronosGroup/OpenCL-SDK>

The release will already include the CPP bindings.

#### Linux

Linux, needs the OpenCL development libraries:

```bash
sudo apt install opencl-headers ocl-icd-opencl-dev -y
```

#### MacOS

Install the OpenCL development libraries with Homebrew:

```bash
brew install opencl-icd-loader
brew install opencl-headers
```

### Build

Once you have set up your OS you can now build the project.
You can either load it with your IDE (Visual Studio, Clion, etc...), or use the command line.

To use the command line build, type the following command at the proejct root folder.

```bash
cmake -B <output directory> -DCMAKE_BUILD_TYPE=<build optimization flag>
```

example:

```bash
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
```

To set up cmake build in the `build` folder as a `release` optimized build.

Then, you can build the project with the following command:

```bash
cmake --build <output directory> --config <build optimization flag>
```

example:

```bash
cmake --build ./build --config Release
```

To build the project in the `build` folder as a `release` optimized build.

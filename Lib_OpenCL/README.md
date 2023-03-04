# OpenCL

Version: OpenCL 3.0

OpenCL is a framework for writing programs that execute across heterogeneous platforms consisting of CPUs, GPUs, DSPs,
FPGAs, and other processors or hardware accelerators.

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

#### Windows

For windows, you need to install the OpenCL SDK from the Khronos website:  
<https://www.khronos.org/opencl/>

#### Linux

Linux, needs the OpenCL development libraries:

```bash
sudo apt install ocl-icd-opencl-dev
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

# OpenMPI

Version: 4.0.3

The OpenMPI example calculates twin primes in parallel. It is based on my project at the link below:
https://github.com/Im-Rises/cTwinPrimeNumberParallel/tree/main

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

OpenMPI is only available for Linux and macOS.

#### Linux

Linux, needs the OpenMPI development libraries:

```bash
sudo apt-get install openmpi-bin openmpi-common libopenmpi-dev libgtk2.0-dev
```

#### MacOS

Install the OpenMPI development libraries with Homebrew:

```bash
brew install open-mpi
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

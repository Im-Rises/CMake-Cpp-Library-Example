# PThreads

PTHREADS is a library that allows you to create threads in C++.
It is available on Linux and macOS, but not on Windows.

## How to compile

### Setup

The PThreads library is generally installed by default on Linux and macOS.

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

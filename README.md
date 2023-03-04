# CMake-Cpp-Library-Example

<p align="center">
      <img src="https://user-images.githubusercontent.com/59691442/183268126-b3d19e66-8f2d-463a-805e-ae6ef7cc6c01.png" alt="cmakeLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="cppLogo" style="height:60px;"/>
      <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="cppLogo" style="height:60px;"/>
</p>

## Description

This is a set of simple examples of how to use CMake to build C++ projects with different libraries.

All the examples are made to be compiled with CMake for Windows, Linux and macOS, except for some like PThreads that are
only available on Linux.

Each directory contains a CMakeLists.txt file that is used to build the library, the complete explanation are in the
README.md file of each directory.

## Todo

- [ ] Create a cmake script for each library test or one job for each library
- [ ] Add more libraries

## Library list

- [x] OpenMP
- [x] OpenCL
- [x] OpenCV
- [x] OpenMPI
- [x] PThreads
- [x] SDL2
- [x] SFML

## Set of libraries

- [ ] GLFW + GLAD + OpenGL
- [ ] GLFW + GLAD + OpenGL + ImGui
- [ ] GLFW + Vulkan
- [ ] GLFW + Vulkan + ImGui

## Library not documented

- [ ] Boost
- [ ] Qt
- [ ] ...

## Compilator list

- [ ] Emscripten compilation

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to the README.md file of
each directory.

You will need cmake to build the project. You can download it here:  
<https://cmake.org/download/>

> **Note:**
> If you are using an IDE, the project build selection is integrated in it. You do not need the command line to build
> the project.

## Build all projects by command line

Once you have set up your OS you can now build the project. You can either load it with your IDE (Visual Studio, Clion,
etc...), or use the command line.

To use the command line build, type the following command at the project root folder.

```bash
cmake -B <build directory> -DCMAKE_BUILD_TYPE=<build optimization flag>
```

example:

```bash
cmake -B ./build -DCMAKE_BUILD_TYPE=Release
```

Then type

```bash
cmake --build <build directory> --config <build optimization flag>
```

example:

```bash
cmake --build ./build --config Release
```

## Build a specific project by command line

To build a specific project, you can use the following command:

```bash
cmake -S . -B build -D PROJECT_TO_BUILD=<project name> -DCMAKE_BUILD_TYPE=<build optimization flag>
```

example:

```bash
cmake -S . -B ./build -D PROJECT_TO_BUILD=Lib_OpenMP -DCMAKE_BUILD_TYPE=Release
```

Then type

```bash
cmake --build <build directory> --config <build optimization flag>
```

example:

```bash
cmake --build ./build --config Release
```

> **Note**
> You can build several projects at the same time by separating the project names with a semicolon.
> example:
> ```bash
> cmake -S . -B ./build -D PROJECT_TO_BUILD=Lib_OpenMP;Lib_OpenCL -DCMAKE_BUILD_TYPE=Release
> ```

> **Warning**  
> After building one of the project you may need to reset the cache of CMake to build another project.
> To do so, start of the `clean.sh` or `clean.bat` script.

## GitHub Actions

[![CMake](https://github.com/Im-Rises/CMake-Cpp-Library-Example/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/Im-Rises/CMake-Cpp-Library-Example/actions/workflows/cmake.yml)
[![cpp-linter](https://github.com/Im-Rises/CMake-Cpp-Library-Example/actions/workflows/cpp-linter.yml/badge.svg?branch=main)](https://github.com/Im-Rises/CMake-Cpp-Library-Example/actions/workflows/cpp-linter.yml)

The project is set with a set of different scripts:

- CMake: This script is used to build the project.
- Cpp Linter: This script is used to check the code for security issues.

## Libraries

OpenMP:  
<https://www.openmp.org/>

SDL2:  
<https://www.libsdl.org/>

SFML:  
<https://www.sfml-dev.org/>

## Documentation

cliutils:  
<https://cliutils.gitlab.io/modern-cmake/chapters/packages/OpenMP.html>

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributors

Quentin MOREL:

- @Im-Rises
- <https://github.com/Im-Rises>

[![GitHub contributors](https://contrib.rocks/image?repo=Im-Rises/CMake-Cpp-Library-Example)](https://github.com/Im-Rises/CMake-Cpp-Library-Example/graphs/contributors)

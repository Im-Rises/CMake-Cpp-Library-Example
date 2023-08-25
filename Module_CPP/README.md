# Module_CPP

This is a simple exemple of how to create a C++ project with CMake using C++20 modules.

## Use other version of CMake

For this example you need CMake 3.26 or higher, if you want to use another version of CMake, you will need to change the
`cmake_minimum_required` line in the `CMakeLists.txt` file.

You'll also need to change the CMake API key in the `CMakeLists.txt` file at the intialisation (in my case not
the `CMakeLists.txt` of this project but the project root `CMakeLists.txt`.

```cmake
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 2182bf5c-ef0d-489a-91da-49dbc3090d2a)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
```

To find the correct API key, check the CMake website to get the current API key for the version of CMake you want to
use.

## How to compile

Simply type the following command at the project root folder.

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
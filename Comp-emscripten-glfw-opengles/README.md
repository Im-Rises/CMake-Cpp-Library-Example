# Comp-emscripten-glfw-opengles

To build the project, you need to use a UNIX system, like Ubuntu or if you're on Windows you can use WSL.

The project is made to be buildable as a desktop application, but it can also be build as a web application with
Emscripten.

> **Note**  
> The project can also be build as a desktop app, if you use directly your IDE or the normal CMake commands like
> in the other examples:
> `cmake -B <output directory> -DCMAKE_BUILD_TYPE=<build optimization flag>`  
> `cmake --build <output directory> --config <build optimization flag>`

## Setup

Then you have to install Emscripten. You can find
instructions on how to install Emscripten here:  
<https://emscripten.org/docs/getting_started/downloads.html>

You also need to have CMake installed. You can find instructions on how to
install CMake here:  
<https://cmake.org/install/>

> **Note**  
> The project is configured for linux, using another OS may require some changes.
> If you are using Windows, you can use WSL to build the project like it is recommended by Emscripten team.

## Build the project

Once you have Emscripten and CMake installed run this command in the project root directory:

```bash
emcmake cmake .
```

Then run this command in the same directory:

```bash
emmake make
```

The commands have to be run in the project Comp-emscripten-glfw-opengles directory.

## Test the web build

To test the project, you can use a web server. You can use the `python` web server for example:
You can install python from here: <https://www.python.org/downloads/>

Then run this command in the build directory:

```bash
python -m http.server
```

Be careful, to type the command in the build directory.

Then open your browser and go to <http://localhost:8000>

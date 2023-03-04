# glfw-glad-opengl-imgui-docking

Version: GLFW 3.3.8, GLAD 0.1.36, OpenGL 3.3, ImGui Docking 1.89.3

This is a simple CMake project that uses GLFW, GLAD and OpenGL, it creates an OpenGL window and draws a triangle.

The project use GLFW to create the window and handle the events, GLAD to load the OpenGL functions and OpenGL to draw
the triangle.

> **Note**  
> This project use the ImGui docking branch, which is not yet merged into the main branch.
> To use the main branch just replace the `imgui` folder with the one from the main branch and
> command the line that enable docking and viewport in the `main.cpp` file.  
> `io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;`  
> `io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;`

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

#### Windows

No step needed, the files are already in the `dependencies` folder.
Be sure to put the `glfw.dll` files next to your executable, if not the program will compile and start, but it'll end up
crashing immediately. The dll files are located in the `dependencies\glfw\lib` folder.

If you want to use another compiler, you will have to replace the correct `.lib` and `.dll` files by the ones from the
compiler you use MinGW, etc...

#### Linux

For Linux, you will need to install the GLFW development libraries.

```bash
sudo apt-get install libglfw3-dev
```

#### MacOS

Install the GLFW development libraries with Homebrew:

```bash
brew install glfw
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

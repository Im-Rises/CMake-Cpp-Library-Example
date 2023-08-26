# Comp-emscripten-react

Version: GLFW 3.3.8, GLAD 0.1.36, OpenGL 3.3, OpenGL ES 3.0

To build the project, you need to use a UNIX system, like Ubuntu or if you're on Windows you can use WSL.

## Setup

You have to install Emscripten. You can find
instructions on how to install Emscripten here:  
<https://emscripten.org/docs/getting_started/downloads.html>

You also need to have CMake installed. You can find instructions on how to
install CMake here:  
<https://cmake.org/install/>

You also need to install glfw. You can install it by typing this command:

```bash
sudo apt install libglfw3-dev
```

> **Note**  
> The project is configured for linux, using another OS may require some changes.
> If you are using Windows, you can use WSL to build the project like it is recommended by Emscripten team.

Of course, you need React installed. You can install it by typing this command.
There is a different way to create a React project. You can find more information here:
<https://reactjs.org/docs/create-a-new-react-app.html>

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

## Run the project

Just build the react website with the command:

```bash
npm run build
```

Then run the command:

```bash
emrun --no_browser --port 8080 .
```

To run the project, you need to go to the website:  
<http://localhost:8080/>
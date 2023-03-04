# SFML

Version: SFML 2.5.1

For this example, I used the SFML library to create a window and display a texture.

The binaries used for Windows compilation are for the MSVC compiler (Visual Studio 2019). If you want to use another
compiler, you will have to replace the correct `.lib` and `.dll` files by the ones from the compiler you use MinGW,
etc...

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

#### Windows

No step needed, the files are already in the `dependencies` folder.
Be sure to put the `SFML.dll` file next to your executable, if not the program will compile and start but it'll end up
crashing immediately.

If you want to use another compiler, you will have to replace the correct `.lib` and `.dll` files by the ones from the
compiler you use MinGW, etc...

#### Linux

```bash
sudo apt-get install libsfml-dev
```

#### MacOS

Install the SFML development libraries with Homebrew:

```bash
brew install sfml
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

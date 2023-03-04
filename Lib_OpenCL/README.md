# OpenCL

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

#### Windows

Windows has no setup needed. It is normally already installed on your computer or your compiler will install it for you.

#### Linux

```bash
sudo apt install libomp-dev
```

#### MacOS

Install the OpenCL development libraries with Homebrew:

```bash
brew install libomp
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

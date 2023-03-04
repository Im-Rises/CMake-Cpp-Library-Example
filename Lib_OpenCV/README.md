# OpenCV

Version: OpenCV 4.7.0

OpenCV is a library of programming functions mainly aimed at real-time computer vision.

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

OpenCV is a library that needs to be installed on your system.
I provided the setup files for windows, but you should build them yourself.
To do so, follow the instructions on the OpenCV website:
<https://docs.opencv.org/master/d3/d52/tutorial_windows_install.html>

#### Windows

For windows, you need to install the OpenCV SDK from the website below:  
<https://opencv.org/releases/>

#### Linux

Linux, needs the OpenCV development libraries:

```bash
sudo apt install libopencv-dev
```

#### MacOS

Install the OpenCV development libraries with Homebrew:

```bash
brew install opencv
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

# OpenCV

Version: OpenCV 4.7.0

OpenCV is a library of programming functions mainly aimed at real-time computer vision.

## How to compile

According to your OS, the build setup is different. Check the appropriate indication according to your os below.

### Setup

OpenCV is a library that needs to be installed on your system.
I provided the setup files for windows, but you should build them yourself.
To do so, follow the instructions on the OpenCV website:
<https://docs.opencv.org/4.x/df/d65/tutorial_table_of_content_introduction.html>

> **Warning:**
> OpenCV is a very large library, and the compilation can take a long time.
> Be also sure to always build the `Release` version of the library, the `Debug` have some issues.

#### Windows

For windows, you need to install the OpenCV SDK from the website below:  
<https://opencv.org/releases/>

Once you have download the `windows.exe` file, double-click on it to unpack the SDK.
Then put the files in the `dependencies` folder of the project with this architecture:

~~~
Project
├── dependencies
│   ├── opencv
│   │   ├── build
│   │   │   |── *
│   │   ├── sources
│   │   │   |── *
│   CMakeLists.txt
│   ├── src
│   │   |─── main.cpp
│   │   |─── CMakelists.txt
│   README.md
~~~

#### Linux

Linux, needs the OpenCV development libraries to be installed on your system.
To do so, follow the instructions on the OpenCV website:
<https://docs.opencv.org/4.x/df/d65/tutorial_table_of_content_introduction.html>

You don't need to put the OpenCV files in the `dependencies` folder.

#### MacOS

MacOS, needs the OpenCV development libraries to be installed on your system.
To do so, follow the instructions on the OpenCV website:
<https://docs.opencv.org/4.x/df/d65/tutorial_table_of_content_introduction.html>

You don't need to put the OpenCV files in the `dependencies` folder.

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

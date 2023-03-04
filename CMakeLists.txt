cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project("Lib_SDL2")
add_subdirectory(${PROJECT_NAME})

project("Lib_SFML")
add_subdirectory(${PROJECT_NAME})


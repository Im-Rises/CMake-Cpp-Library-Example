cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 2182bf5c-ef0d-489a-91da-49dbc3090d2a)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

# If PROJECT_TO_BUILD is defined, only build the specified project
if (PROJECT_TO_BUILD)
    #    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_TO_BUILD})
    foreach (project ${PROJECT_TO_BUILD})
        message("Building ${project}")
        project(${project})
        add_subdirectory(${project})
    endforeach ()
else ()
    add_subdirectory("Comp-emscripten-glfw-opengles")

    add_subdirectory("Comp-emscripten-glfw-opengles-imgui")

    add_subdirectory("Comp-emscripten-sdl2-opengles")

    add_subdirectory("Comp-emscripten-sdl2-opengles-imgui")

    project("Lib_OpenCL")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_OpenCL_CPP")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_OpenCV")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_OpenMP")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_OpenMPI")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_PThreads")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_SDL2")
    add_subdirectory(${PROJECT_NAME})

    project("Lib_SFML")
    add_subdirectory(${PROJECT_NAME})

    project("Libs-glfw-glad-opengl")
    add_subdirectory(${PROJECT_NAME})

    project("Libs-glfw-glad-opengl-imgui")
    add_subdirectory(${PROJECT_NAME})

    project("Libs-sdl2-glad-opengl")
    add_subdirectory(${PROJECT_NAME})

    project("Libs-sdl2-glad-opengl-imgui")
    add_subdirectory(${PROJECT_NAME})

    project("CPP_Modules")
    add_subdirectory(${PROJECT_NAME})
endif ()

cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

    project("Lib_OpenCL")
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
endif ()

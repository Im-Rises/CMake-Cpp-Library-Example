cmake_minimum_required(VERSION 3.14)

if (UNIX AND NOT APPLE)
    project("Comp-emscripten-sdl2-opengles")

    set(Dependency_Dir ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies)

    # Find the SDL2 library
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})

    if (EMSCRIPTEN)
        set(CMAKE_EXECUTABLE_SUFFIX ".html")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s FULL_ES3=1 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")
    endif ()

    include_directories(${Dependency_Dir})
    include_directories(${Dependency_Dir}/glad/include)

    add_executable(${PROJECT_NAME} main.cpp
            ${Dependency_Dir}/glad/src/glad.c
            )

    target_link_libraries(${PROJECT_NAME} SDL2)

    if (EMSCRIPTEN)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)
        set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "index")
    else()
        # Find OpenGL and set OpenGL_GL_PREFERENCE to GLVND
        set(OpenGL_GL_PREFERENCE GLVND)
        find_package(OpenGL 3.3 REQUIRED)

        # Link OpenGL
        target_link_libraries(${PROJECT_NAME} OpenGL::GL)
    endif()
endif ()

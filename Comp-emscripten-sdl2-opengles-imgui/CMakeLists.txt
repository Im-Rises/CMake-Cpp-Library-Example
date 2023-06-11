cmake_minimum_required(VERSION 3.14)

if (UNIX AND NOT APPLE)
    project("Comp-emscripten-sdl2-opengles-imgui")

    set(Dependency_Dir ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies)

    if (EMSCRIPTEN)
        set(CMAKE_EXECUTABLE_SUFFIX ".html")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_SDL=2 -s FULL_ES3=1 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")
    endif ()

    include_directories(${Dependency_Dir})
    include_directories(${Dependency_Dir}/glad/include)

    add_executable(${PROJECT_NAME} main.cpp
            ${Dependency_Dir}/glad/src/glad.c
            ${Dependency_Dir}/imgui/imgui.cpp
            ${Dependency_Dir}/imgui/imgui_demo.cpp
            ${Dependency_Dir}/imgui/imgui_draw.cpp
            ${Dependency_Dir}/imgui/imgui_impl_sdl2.cpp
            ${Dependency_Dir}/imgui/imgui_impl_opengl3.cpp
            ${Dependency_Dir}/imgui/imgui_tables.cpp
            ${Dependency_Dir}/imgui/imgui_widgets.cpp
            )

    # Find the SDL2 library
    find_package(SDL2 REQUIRED)

    include_directories(${SDL2_INCLUDE_DIRS})

    target_link_libraries(${PROJECT_NAME} SDL2)

    set(OpenGL_GL_PREFERENCE GLVND)
    find_package(OpenGL 3.3 REQUIRED)

    # Link OpenGL
    target_link_libraries(${PROJECT_NAME} OpenGL::GL)


    if (EMSCRIPTEN)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)
        set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "index")
    endif ()
endif ()

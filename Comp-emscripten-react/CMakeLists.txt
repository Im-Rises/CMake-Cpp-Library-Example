cmake_minimum_required(VERSION 3.14)

if (UNIX AND NOT APPLE)
    project("comp-emscripten-react")

    set(Dependency_Dir ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies)

    if (EMSCRIPTEN)
        set(CMAKE_EXECUTABLE_SUFFIX ".html")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s MODULARIZE=1 -s WASM=1 -s EXPORT_ES6=1 -s NO_FILESYSTEM=1 -s FULL_ES3=1 -s USE_GLFW=3")
    endif ()

    include_directories(${Dependency_Dir})
    include_directories(${Dependency_Dir}/glad/include)

    add_executable(${PROJECT_NAME} main.cpp
            ${Dependency_Dir}/glad/src/glad.c
            ${Dependency_Dir}/imgui/imgui.cpp
            ${Dependency_Dir}/imgui/imgui_demo.cpp
            ${Dependency_Dir}/imgui/imgui_draw.cpp
            ${Dependency_Dir}/imgui/imgui_impl_glfw.cpp
            ${Dependency_Dir}/imgui/imgui_impl_opengl3.cpp
            ${Dependency_Dir}/imgui/imgui_tables.cpp
            ${Dependency_Dir}/imgui/imgui_widgets.cpp
            )

    target_link_libraries(${PROJECT_NAME} glfw)

    if (EMSCRIPTEN)
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/demo-react-emscripten/src/emscripten-module)
    endif ()
endif ()

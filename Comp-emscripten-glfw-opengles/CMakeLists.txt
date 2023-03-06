cmake_minimum_required(VERSION 3.14)

if (UNIX AND NOT APPLE)
    project("Comp-emscripten-glfw-opengles")

    set(Dependency_Dir ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies)

    if (EMSCRIPTEN)
        set(CMAKE_EXECUTABLE_SUFFIX ".html")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s FULL_ES3=1 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1")
    endif ()

    include_directories(${Dependency_Dir}/glad/include)

    add_executable(${PROJECT_NAME} main.cpp ${Dependency_Dir}/glad/src/glad.c)

    target_link_libraries(${PROJECT_NAME} glfw)

    if (EMSCRIPTEN)
        file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)
        set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)
        set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "index")
    endif ()
endif ()

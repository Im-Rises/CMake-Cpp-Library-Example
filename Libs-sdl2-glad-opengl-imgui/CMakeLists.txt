# Include header files
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/imgui")

# Add executable
add_executable(${PROJECT_NAME} main.cpp
        "${CMAKE_SOURCE_DIR}/dependencies/glad/src/glad.c"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui.cpp"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_demo.cpp"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_draw.cpp"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_impl_sdl2.cpp"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_impl_opengl3.cpp"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_tables.cpp"
        "${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_widgets.cpp"
        )

# Find the SDL2 library
find_package(SDL2 REQUIRED)

# Include the SDL2 include directory
if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/dependencies/SDL2/include)
elseif (UNIX)
    include_directories(${SDL2_INCLUDE_DIRS})
else ()
    message(FATAL_ERROR "Unsupported platform")
endif ()

# Link the SDL2 library
if (WIN32)
    target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)
elseif (APPLE)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
elseif (UNIX)
    target_link_libraries(${PROJECT_NAME} SDL2)
else ()
    message(FATAL_ERROR "Unsupported platform")
endif ()

# Find OpenGL and set OpenGL_GL_PREFERENCE to GLVND
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL 3.3 REQUIRED)

# Link OpenGL
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

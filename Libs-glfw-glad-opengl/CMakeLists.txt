# Include header files
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glad/include")
include_directories("${CMAKE_SOURCE_DIR}/dependencies/glfw/include")

# Add executable
add_executable(${PROJECT_NAME} main.cpp
        "${CMAKE_SOURCE_DIR}/dependencies/glad/src/glad.c")

# Find OpenGL and set OpenGL_GL_PREFERENCE to GLVND
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL 3.0 REQUIRED)

# Link OpenGL
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

# Link GLFW
if (WIN32)
    if (MSVC)
        target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-vc2019/glfw3.lib")
    elseif (MINGW)
        target_link_libraries(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/dependencies/glfw/lib-mingw-w64/libglfw3.a")
    endif ()
elseif (UNIX)
    find_package(glfw3 3.3 REQUIRED)
    target_link_libraries(${PROJECT_NAME} glfw ${CMAKE_DL_LIBS})
else ()
    message(FATAL_ERROR "OS not configured in CMakeLists.txt")
endif ()

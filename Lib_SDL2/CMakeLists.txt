# Add SDL2 to prefix path
if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/SDL2/cmake)
endif ()

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

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

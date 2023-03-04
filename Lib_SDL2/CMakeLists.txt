# Include the SDL2 include directory
include_directories(${CMAKE_SOURCE_DIR}/dependencies/SDL2/include)

# Add SDL2 to prefix path
#list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/SDL2/cmake)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/SDL2/cmake)

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the SDL2 library
find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)

## Link the SDL2 library according to the OS
#if(WIN32)
#    set(SDL2PATH ${CMAKE_SOURCE_DIR}/dependencies/SDL2/lib/)
#    target_link_libraries(${PROJECT_NAME} ${SDL2PATH}x64/SDL2.lib)
#elseif(UNIX)
#    find_package(SDL2 REQUIRED)
#    target_link_libraries(${PROJECT_NAME} SDL2)
#else()
#    message(FATAL_ERROR "OS not configured in CMakeLists.txt")
#endif()

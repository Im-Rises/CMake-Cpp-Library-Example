# Find .cmake files and include OpenCL headers
if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/OpenCL/share/cmake/OpenCL)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/OpenCL/share/cmake/OpenCLHeaders)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/OpenCL/share/cmake/OpenCLICDLoader)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/OpenCL/share/cmake/OpenCLHeadersCpp)
    include_directories(${CMAKE_SOURCE_DIR}/dependencies/OpenCL/include)
endif ()

message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Find and configure OpenCL package
if (WIN32)
    find_package(OpenCL CONFIG REQUIRED COMPONENTS Headers HeadersCpp)
else ()
    find_package(OpenCL REQUIRED)
endif ()

# Create executable
add_executable(${PROJECT_NAME} main.cpp)

# Link OpenCL libraries and set compile definitions
if (WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenCL::OpenCL OpenCL::Headers OpenCL::HeadersCpp)
else ()
    target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCL_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCL_LIBRARIES})
endif ()

# Include OpenCL headers
include_directories(${OpenCL_INCLUDE_DIRS})

# Add executable
add_executable(${PROJECT_NAME} "main.c")

# Find OpenCL
find_package(OpenCL REQUIRED)

# Link OpenCL
link_directories(${OpenCL_LIBRARY})

# Link executable
target_link_libraries(${PROJECT_NAME} OpenCL::OpenCL)

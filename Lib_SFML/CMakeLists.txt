# Include the SFML include directory
include_directories(${CMAKE_SOURCE_DIR}/dependencies/SFML/include)

# Set the SFML libraries to link
set(SFML_COMPONENTS audio network graphics window system)
set(SFML_LINKED_LIBRARIES sfml-audio sfml-network sfml-graphics sfml-window sfml-system)

# Set the SFML cmake directory
if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/dependencies/SFML/lib/cmake/SFML")
endif ()

# Find the SFML libraries and components
find_package(SFML 2.5.1 REQUIRED COMPONENTS ${SFML_COMPONENTS})

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link the SFML libraries
target_link_libraries(${PROJECT_NAME} ${SFML_LINKED_LIBRARIES})

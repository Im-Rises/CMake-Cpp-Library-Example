# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Add OpenMP
if (UNIX)
    find_package(OpenMP REQUIRED) # Add -fopenmp to compiler flags
    #if (OpenMP_C_FOUND)
    #    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_C)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_C)
elseif (WIN32) # Add some link for the new Task system
    find_package(Threads REQUIRED)
    add_library(OpenMP::OpenMP_C IMPORTED INTERFACE)
    set_property(TARGET OpenMP::OpenMP_C
            PROPERTY INTERFACE_COMPILE_OPTIONS ${OpenMP_C_FLAGS})
    set_property(TARGET OpenMP::OpenMP_C
            PROPERTY INTERFACE_LINK_LIBRARIES ${OpenMP_C_FLAGS} Threads::Threads)
endif ()

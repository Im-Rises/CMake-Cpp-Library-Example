if (UNIX)
    # Add the executable
    add_executable(${PROJECT_NAME} main.cpp)

    # Find MPI
    find_package(MPI REQUIRED)

    # Link MPI
    target_link_libraries(${PROJECT_NAME} PUBLIC MPI::MPI_CXX) # Replace MPI_CXX with MPI_C if you are using C
    target_link_libraries(${PROJECT_NAME} PUBLIC -lm) # Link math library for the demo
else ()
    message("MPI cannot be compiled for other systems than UNIX (skipping build)")
endif ()

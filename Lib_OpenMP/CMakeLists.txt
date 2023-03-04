# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Add OpenMP
if (UNIX)
    find_package(OpenMP REQUIRED) # Add -fopenmp to compiler flags
    #if (OpenMP_CXX_FOUND)
    #    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)
elseif (WIN32) # Add some link for the new Task system
    #    find_package(Threads REQUIRED)
    add_library(OpenMP::OpenMP_CXX IMPORTED INTERFACE)
    set_property(TARGET OpenMP::OpenMP_CXX
            PROPERTY INTERFACE_COMPILE_OPTIONS ${OpenMP_CXX_FLAGS})
    #    set_property(TARGET OpenMP::OpenMP_CXX
    #            PROPERTY INTERFACE_LINK_LIBRARIES ${OpenMP_CXX_FLAGS} Threads::Threads)
endif ()

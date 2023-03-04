if (NOT APPLE)

    # Find .cmake files and include OpenCL headers
    if (WIN32)
        list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/OpenCL/share/cmake/OpenCL)
        include_directories(${CMAKE_SOURCE_DIR}/dependencies/OpenCL/include)
    endif ()

    # Find OpenCL
    if (WIN32)
        find_package(OpenCL CONFIG REQUIRED)
    else ()
        find_package(OpenCL REQUIRED)
    endif ()

    # Create executable target
    add_executable(${PROJECT_NAME} main.cpp)

    if (WIN32)
        # Link OpenCL library
        target_link_libraries(${PROJECT_NAME} PRIVATE OpenCL::OpenCL)
    else ()
        # Include OpenCL headers
        target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCL_INCLUDE_DIR})
        # Link OpenCL library
        target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCL_LIBRARIES})
    endif ()

endif ()

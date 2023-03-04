if (UNIX)
    # Set threads flag to prefer pthreads
    set(THREADS_PREFER_PTHREAD_FLAG ON)

    # Add executable
    add_executable(${PROJECT_NAME} main.cpp)

    # Find pthreads
    find_package(Threads REQUIRED)

    # Link pthreads
    target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
else ()
    message("pthread cannot be compiled for other systems than UNIX (skipping build)")
endif ()

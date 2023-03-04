# Add executable
add_executable(${PROJECT_NAME} main.cpp)

# Add OpenMP
find_package(OpenMP REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenMP_CXX_LIBRARIES})
#if (OpenMP_CXX_FOUND)
#    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
#endif ()

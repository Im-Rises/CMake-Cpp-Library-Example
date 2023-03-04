include_directories(${CMAKE_SOURCE_DIR}/dependencies/OpenCV/include)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/OpenCV)

add_executable(${PROJECT_NAME} main.cpp)

find_package(OpenCV REQUIRED)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

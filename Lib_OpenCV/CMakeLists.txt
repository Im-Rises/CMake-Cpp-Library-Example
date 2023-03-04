add_executable(${PROJECT_NAME} main.cpp)

if (WIN32)
    list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/dependencies/opencv/build)
endif ()

find_package(OpenCV REQUIRED)

if (WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/dependencies/opencv/build/include)
elseif (UNIX)
    include_directories(${OpenCV_INCLUDE_DIRS})
endif ()

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

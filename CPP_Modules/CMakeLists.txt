cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 2182bf5c-ef0d-489a-91da-49dbc3090d2a)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

# List of target names
set(target_names
        foo
        )
set(full_target_filenames "")
set(target_extension "cpp")

# Function to add and configure a target
function(add_and_configure_target TARGET_NAME)
    add_library(${TARGET_NAME} STATIC)

    target_sources(
            ${TARGET_NAME} PRIVATE
            FILE_SET cxx_modules TYPE CXX_MODULES FILES
            "${TARGET_NAME}.ixx"
    )

    target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)
endfunction()

# Loop over the target names and call the function for each
foreach (target_name ${target_names})
    add_and_configure_target(${target_name})
    list(APPEND full_target_filenames "${target_name}.${target_extension}")
endforeach ()

add_executable(${PROJECT_NAME} "main.cpp" "${full_target_filenames}")

target_link_libraries(${PROJECT_NAME} PRIVATE foo)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

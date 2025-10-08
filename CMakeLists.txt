cmake_minimum_required(VERSION 3.22)
project(difiplotter VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Find SFML using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-all)

# Add executable
add_executable(${PROJECT_NAME} 
    src/main.cpp
)

# Link SFML libraries
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SFML_LIBRARIES})
target_compile_options(${PROJECT_NAME} PRIVATE ${SFML_CFLAGS_OTHER})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Copy assets to build directory
file(COPY assets/ DESTINATION ${CMAKE_BINARY_DIR}/bin/assets/)

# Enable compiler warnings
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

# Print build information
message(STATUS "Building ${PROJECT_NAME} version ${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")

# Optional: Install target
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

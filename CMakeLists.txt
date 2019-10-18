cmake_minimum_required(VERSION 3.0)

project(SmartPtr)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/main.cpp
)

# Add an executable with the above sources
add_executable(SmartPtr ${SOURCES})


target_include_directories(SmartPtr
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
cmake_minimum_required(VERSION 3.0)

project (SmartPtr)


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
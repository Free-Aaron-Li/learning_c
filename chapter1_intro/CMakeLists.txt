cmake_minimum_required(VERSION 3.29)
project(chapter1)

set(CMAKE_C_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ../bin)

link_directories(${PROJECT_SOURCE_DIR}/lib)

set_directory_properties(${PROJECT_SOURCE_DIR}/asset)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin/)

set(SOURCES
        src/main.c
        test/test1.h
        test/test1.c
)

#------------------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/test
)

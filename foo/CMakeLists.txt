cmake_minimum_required(VERSION 3.0)
project(foo C CXX)

file(GLOB_RECURSE SOURCE_LIST
    "src/*.c*"
)

add_library(foo SHARED ${SOURCE_LIST})
#message("[DEBUG]** " ${SOURCE_LIST})

target_include_directories(foo 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#target_link_libraries(foo
#    PRIVATE simulator_stub
#)
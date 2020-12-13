cmake_minimum_required(VERSION 3.0)
project(simulator_stub C CXX)

# Moduleごとプロジェクトを分けたほうがいいのかな？
# 依存関係がごちゃるので問題が出るかも
file(GLOB_RECURSE SOURCE_LIST
    "src/*.c*"
)

add_library(simulator_stub ${SOURCE_LIST})
#message("[DEBUG]** " ${SOURCE_LIST})

target_include_directories(simulator_stub 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

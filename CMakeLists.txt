####################################################################
# 基本設定
####################################################################
cmake_minimum_required(VERSION 3.0)
project(test.out C CXX)

####################################################################
# ソースコード抽出
####################################################################
option(TEST_TYPE_IT "make module a integration test" ON)
if(TEST_TYPE_IT)
    message("** Build module for integration test")
    # 基本テストコード抽出
    # GLOBでソースコードのリストを取得するのは非推奨
    file(GLOB_RECURSE SOURCE_LIST
        "integration_test/foo/*"
    )
    # message(${SOURCE_LIST})
else()
    message("** Build module for unit test") 
    # 単体テストコード抽出
    file(GLOB_RECURSE SOURCE_LIST
        "unit_test/*"
    )
endif()
unset(TEST_TYPE_IT)

# Stub Modules
add_subdirectory(simulator_stub)

# 実行ファイル生成
add_executable(test.out "integration_test/it_main.cpp" ${SOURCE_LIST})
add_subdirectory(foo)

####################################################################
# ライブラリのリンク
# リンクエラーとなるため、呼び出される側のライブラリを下方にに記述すること
####################################################################
# foo 
# 一度ビルドをしたあとでないとfind_libraryは出来ないので、絶対パスで指定
target_include_directories(test.out PRIVATE ${PROJECT_SOURCE_DIR}/foo/include)
target_link_libraries(test.out ${CMAKE_CURRENT_BINARY_DIR}/foo/libfoo.so)

# stub用のライブラリを読み込ませるため、リンクディレクトリの追加
# 本当はfooに対してリンクさせたい
link_directories(${CMAKE_CURRENT_BINARY_DIR}/simulator_stub/)
target_link_libraries(test.out ${CMAKE_CURRENT_BINARY_DIR}/simulator_stub/libsimulator_stub.a)

# Google Test
# GTest_Foundに値が設定されない。よくわからない。
find_package(GTest)
if (GTest_Found)
    message("Found Package GTest ...")
    include(GoogleTest)
    target_include_directories(test.out PRIVATE ${GTEST_INCLUDE_DIRS})
    target_link_libraries(test.out GTest::GTest)
else()
    # google test未インストールの場合は内包のライブラリをリンクさせる
    message("Could NOT find GTest. So Link internal libraries ...")
    find_library(GTEST_LIB NAMES libgtest.a PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ REQUIRED)
    message("Goole Test Lib Path : " ${GTEST_LIB})
    target_link_libraries(test.out ${GTEST_LIB})
    target_include_directories(test.out PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/third_party/include) # ここまでやるならヘッダもfindしろよと思います
endif()

# pthread
# pthread は GoogleTestにも必要
find_package(Threads REQUIRED)
target_link_libraries(test.out Threads::Threads)

# EGL
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake) # find_package 参照先のディレクトリを追加
find_package(EGL)
if(EGL_FOUND)
    message("Found Package EGL ... You minght not have to add include directories")
    target_include_directories(test.out PRIVATE ${EGL_INCLUDE_DIR}) # 必要がなければ消してください
else()
    message("Could NOT find EGL. This is not a problem, is it?")
endif()


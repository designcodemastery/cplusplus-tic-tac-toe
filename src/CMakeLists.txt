cmake_minimum_required(VERSION 3.5)
project(CMakeSetup
        VERSION 1.0.0
        DESCRIPTION "Tic-Tac-Toe Console Application"
        LANGUAGES CXX)

# List our source files
add_executable(tic-tac-toe ../src/main.cpp ../src/Game.cpp)

target_compile_features(tic-tac-toe PRIVATE cxx_std_20)

target_include_directories(tic-tac-toe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

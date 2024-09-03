#!/bin/bash

# Set project folder (current directory)
projectRoot=$(pwd)

# Define folder structure
folders=(
    "src"
    "include"
    "docs"
    "build"
    ".vscode"
    ".github/workflows"
    "docs"
)

# Create folders
for folder in "${folders[@]}"; do
    folderPath="$projectRoot/$folder"
    if [ ! -d "$folderPath" ]; then
        mkdir -p "$folderPath"
        echo "Created folder: $folderPath"
    else
        echo "Folder already exists: $folderPath"
    fi
done

# Define initial files and their contents
declare -A files=(
    ["LICENSE"]="MIT License"
    [".gitignore"]="build/
*.obj
*.o
*.exe
*.dll
*.pdb
*.ilk
*.user
*.log
*.suo
*.sdf
*.ipch
*.opensdf
*.tlog
*.vscode/
*.ncb
*.sln
*.vcxproj
*.vcxproj.filters
*.vcxproj.user
*.vcproj.user
*.cmake
CMakeCache.txt
CMakeFiles/
CMakeScripts/
Testing/
Makefile
cmake_install.cmake
install_manifest.txt
_compile_commands.json
compile_commands.json
CTestTestfile.cmake
_deps/
_build/
_conan/
conanbuildinfo.cmake
conanbuildinfo.txt
conaninfo.txt
_graphics/
__pycache__/
*.pyc"
    ["CMakeLists.txt"]="cmake_minimum_required(VERSION 3.5)
project(TicTacToe)
add_executable(TicTacToe ../src/main.cpp ../src/Game.cpp)"
    ["src/main.cpp"]="// Entry point for the Tic-Tac-Toe application

int main() {
    return 0;
}"
    ["src/Game.hpp"]="// Game class header file"
    ["src/Game.cpp"]="// Game class implementation file"
    ["tests/GameTests.cpp"]="// Unit tests for the Game class"
    [".vscode/settings.json"]="{}"
    [".vscode/tasks.json"]="{}"
    [".vscode/launch.json"]="{}"
    [".github/workflows/ci.yml"]="name: C/C++ CI

# CI workflow for building and testing the project"
    ["docs/index.md"]="# Project Documentation

This folder contains the project documentation."
    ["docs/setup.md"]="# Setup Instructions

Instructions for setting up the development environment."
    ["docs/architecture.md"]="# Architecture Overview

Explanation of the project architecture."
)

# Create files with placeholder content
for path in "${!files[@]}"; do
    filePath="$projectRoot/$path"
    if [ ! -f "$filePath" ]; then
        echo "${files[$path]}" > "$filePath"
        echo "Created file: $filePath"
    else
        echo "File already exists: $filePath"
    fi
done

echo "Project structure setup is complete."

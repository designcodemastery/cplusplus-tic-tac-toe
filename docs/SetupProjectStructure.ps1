# Set project folder (current directory)
$projectRoot = Get-Location

# Define folder structure
$folders = @(
    "src",
    "include",
    "docs",
    "build",
    ".vscode",
    ".github/workflows",
    "docs"
)

# Create folders
foreach ($folder in $folders) {
    $folderPath = Join-Path $projectRoot $folder
    if (-not (Test-Path $folderPath)) {
        New-Item -Path $folderPath -ItemType Directory | Out-Null
        Write-Host "Created folder: $folderPath"
    } else {
        Write-Host "Folder already exists: $folderPath"
    }
}

# Define initial files and their contents
$files = @(
    @{ Path = "LICENSE"; Content = "MIT License" },
    @{ Path = ".gitignore"; Content = "build/
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
*.pyc" },
    @{ Path = "CMakeLists.txt"; Content = "cmake_minimum_required(VERSION 3.5)
project(TicTacToe)
add_executable(TicTacToe ../src/main.cpp ../src/Game.cpp)" },
    @{ Path = "src/main.cpp"; Content = "// Entry point for the Tic-Tac-Toe application

int main() {
    return 0;
}" },
    @{ Path = "src/Game.hpp"; Content = "// Game class header file" },
    @{ Path = "src/Game.cpp"; Content = "// Game class implementation file" },
    @{ Path = "tests/GameTests.cpp"; Content = "// Unit tests for the Game class" },
    @{ Path = ".vscode/settings.json"; Content = "{}" },
    @{ Path = ".vscode/tasks.json"; Content = "{}" },
    @{ Path = ".vscode/launch.json"; Content = "{}" },
    @{ Path = ".github/workflows/ci.yml"; Content = "name: C/C++ CI

# CI workflow for building and testing the project" },
    @{ Path = "docs/index.md"; Content = "# Project Documentation

This folder contains the project documentation." },
    @{ Path = "docs/setup.md"; Content = "# Setup Instructions

Instructions for setting up the development environment." },
    @{ Path = "docs/architecture.md"; Content = "# Architecture Overview

Explanation of the project architecture." }
)

# Create files with placeholder content
foreach ($file in $files) {
    $filePath = Join-Path $projectRoot $file.Path
    if (-not (Test-Path $filePath)) {
        New-Item -Path $filePath -ItemType File -Force -Value $file.Content | Out-Null
        Write-Host "Created file: $filePath"
    } else {
        Write-Host "File already exists: $filePath"
    }
}

Write-Host "Project structure setup is complete."

# Build Process Using Ninja

This document outlines the steps to build the Tic-Tac-Toe game project using CMake with the Ninja build system.

## Prerequisites

- **CMake**: Ensure that CMake is installed on your system. CMake 3.10 or later is required.
- **Ninja**: Ensure that Ninja is installed. You can install it via package managers or from [Ninja's official website](https://ninja-build.org/).

## Build Steps

### 1. Create the `CMakeLists.txt` File

In the root directory of your project, create a file named `CMakeLists.txt`. This file will contain the configuration instructions for CMake. Here is a basic setup I have used (This is my first project using CMake so please be gently on me):

```cmake
cmake_minimum_required(VERSION 3.10)
project(tic-tac-toe VERSION 1.0.0 LANGUAGES CXX)

# Define version number
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# Determine the target OS and architecture
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(OS_NAME "Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(OS_NAME "Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(OS_NAME "macOS")
else()
    set(OS_NAME "UnknownOS")
endif()

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64")
    set(ARCH_NAME "x64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    set(ARCH_NAME "ARM64")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "armv7l")
    set(ARCH_NAME "ARMv7")
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i386|i686")
    set(ARCH_NAME "x86")
else()
    set(ARCH_NAME "UnknownArch")
endif()

# Construct the executable name
set(EXECUTABLE_NAME "tic-tac-toe_v${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}_${ARCH_NAME}_${OS_NAME}")

# Set up the include and source directories
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add the executable target
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Set the output directory for the executable
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build
)
```

### 2. Create a Build Directory

Create a directory to hold the build files and navigate into it:

```bash
mkdir build
cd build
```

### 3. Configure the Project with CMake
Generate the build files using the Ninja generator. This step configures the project and prepares it for building:

```bash
cmake -G Ninja ..
```

### 4. Build the Project
Run Ninja to build the project. This step compiles the source code and links the executable:

```bash
ninja
```

### 5. Run the Executable
After the build process completes, the executable will be located in the build directory. You can run it directly from there:

```bash
./tic-tac-toe_v1.0.0_x64_Linux
```
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

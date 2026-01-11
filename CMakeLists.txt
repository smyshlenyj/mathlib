cmake_minimum_required(VERSION 3.16)
project(mathlib VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs) # Provides CMAKE_INSTALL_*DIR variables for portable install paths

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compiler warnings
add_compile_options(-Wall -Wextra -Wpedantic)

# clang-tidy setup
option(ENABLE_CLANG_TIDY "Enable clang-tidy checks" ON)

if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY NAMES clang-tidy clang-tidy-18 clang-tidy-17)

    if(CLANG_TIDY)
        message(STATUS "clang-tidy found: ${CLANG_TIDY}")
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY}")
    endif()
endif()

# Library
add_library(math STATIC src/mathlib.cpp)
target_include_directories(math PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Install library
install(TARGETS math
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

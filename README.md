# mathlib

`mathlib` is a simple C++ static library providing math utilities under the `mathlib` namespace.
This document explains how to integrate it into your CMake project.

---

## Project Structure

```
mathlib/
├─ include/       # Public header files
│   └─ math.h     # Contains functions inside namespace mathlib
├─ math.cpp       # Library source file
├─ CMakeLists.txt
```

---

## Building the Library

You can build `mathlib` as a standalone library:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

The static library will be generated in `build/` and headers are in `include/`.

---

## Installing the Library

To install the library and headers to the system:

```bash
cmake --install build
```

By default, headers go to `${CMAKE_INSTALL_INCLUDEDIR}` (usually `/usr/local/include`) and the library to `${CMAKE_INSTALL_LIBDIR}` (usually `/usr/local/lib`).

---

## Using `mathlib` in Another Project

### 1. Using `FetchContent` (Recommended)

In your CMake project:

```cmake
include(FetchContent)

FetchContent_Declare(
    mathlib
    GIT_REPOSITORY https://github.com/youruser/mathlib.git
    GIT_TAG main
)

FetchContent_MakeAvailable(mathlib)

add_executable(myapp src/main.cpp)
target_link_libraries(myapp PRIVATE math)
```

Now you can include the headers in your source files and use the namespace:

```cpp
#include "math.h"

int main() {
    int sum = mathlib::add(3, 4);
    int fact = mathlib::factorial(5);
}
```

---

### 2. Using Installed Library

If you installed `mathlib` system-wide:

```cmake
find_package(mathlib REQUIRED)

add_executable(myapp src/main.cpp)
target_link_libraries(myapp PRIVATE math)
target_include_directories(myapp PRIVATE ${CMAKE_INSTALL_INCLUDEDIR})
```

---

## Compiler Settings

- Requires C++17
- Recommended compiler flags: `-Wall -Wextra -Wpedantic`
- Optional: enable `clang-tidy` for static analysis

---

## License

MIT


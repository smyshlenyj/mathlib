# mathlib

`mathlib` is a simple header-only C++ library providing math utilities under the `mathlib` namespace.

---

## Project Structure

```
mathlib/
├─ include/           # Public header files
│   └─ mathlib.hpp    # All functions and implementations inside the mathlib namespace
├─ CMakeLists.txt
```
* All functionality is implemented in mathlib.hpp.
* No separate .cpp files are required.
* Being header-only, mathlib does not produce a compiled library to link against.

---

## Exception handling

Some functions now throw exceptions instead of returning error codes:

| **Functions**      | **Exception Thrown**  | **Condition**     |
|--------------------|:---------------------:|-------------------|
| mathlib::divide    | std::invalid_argument | Division by zero  |
| mathlib::power     | std::invalid_argument | Negative exponent |
| mathlib::factorial | std::invalid_argument | Negative argument |

You should catch exceptions in your project when using these functions:

```c++
#include "mathlib.hpp"
#include <iostream>

int main() {
    try {
        auto result = mathlib::divide(10, 0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
```

## Using `mathlib` in another Project

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
#include "mathlib.hpp"

int main() {
    std::int64_t sum = mathlib::add(3, 4);
    std::int64_t fact = mathlib::factorial(5);
}
```

---

## Compiler Settings

- Requires C++17
- Recommended compiler flags: `-Wall -Wextra -Wpedantic`
- Optional: enable `clang-tidy` for static analysis

---

## License

MIT


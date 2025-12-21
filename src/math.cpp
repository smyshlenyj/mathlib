#include "math.h"

namespace mathlib
{

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

int power(int base, int exp)
{
    int result = 1.0;
    for (int i = 0; i < exp; ++i)
    {
        result *= base;
    }
    return result;
}

std::uint64_t factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
}  // namespace mathlib
#include "math.h"

namespace mathlib
{

MathResult add(int x, int y)
{
    return {x + y, MathError::None};
}

MathResult subtract(int x, int y)
{
    return {x - y, MathError::None};
}

MathResult multiply(int x, int y)
{
    return {x * y, MathError::None};
}

MathResult divide(int x, int y)
{
    if (y == 0)
        return {0, MathError::DivisionByZero};

    return {x / y, MathError::None};
}

MathResult power(int base, int exp)
{
    if (exp < 0)
        return {0, MathError::InvalidArgument};

    std::int64_t result = 1;

    for (std::int64_t i = 0; i < exp; ++i)
    {
        result *= base;
    }

    return {result, MathError::None};
}

MathResult factorial(int n)
{
    if (n < 0)
        return {0, MathError::NegativeFactorial};

    if (n == 0 || n == 1)
        return {1, MathError::None};

    MathResult prev = factorial(n - 1);

    if (prev.error != MathError::None)
        return prev;

    return {n * prev.value, MathError::None};
}

}  // namespace mathlib
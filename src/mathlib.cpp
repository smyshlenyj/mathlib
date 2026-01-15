#include "mathlib.h"

namespace mathlib
{

MathResult add(std::int64_t first, std::int64_t second)
{
    return {first + second, MathError::None};
}

MathResult subtract(std::int64_t first, std::int64_t second)
{
    return {first - second, MathError::None};
}

MathResult multiply(std::int64_t first, std::int64_t second)
{
    return {first * second, MathError::None};
}

MathResult divide(std::int64_t first, std::int64_t second)
{
    if (second == 0)
    {
        return {0, MathError::DivisionByZero};
    }

    return {first / second, MathError::None};
}

// --------------------
// Safe power function
// --------------------
MathResult power(Base base, Exponent exponent)
{
    if (exponent.value < 0)
    {
        return {0, MathError::InvalidArgument};
    }

    std::int64_t result = 1;

    for (std::int64_t i = 0; i < exponent.value; ++i)
    {
        result *= base.value;
    }

    return {result, MathError::None};
}

MathResult factorial(std::int64_t n)
{
    if (n < 0)
    {
        return {0, MathError::NegativeFactorial};
    }

    if (n == 0 || n == 1)
    {
        return {1, MathError::None};
    }

    MathResult prev = factorial(n - 1);

    if (prev.error != MathError::None)
    {
        return prev;
    }

    return {n * prev.value, MathError::None};
}

}  // namespace mathlib

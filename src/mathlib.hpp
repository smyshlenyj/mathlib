#pragma once
#include <cstdint>  // std::int64_t, std::uint8_t

namespace mathlib
{

// --------------------
// Strong typedefs for power
// --------------------
struct Base
{
    std::int64_t value;
};

struct Exponent
{
    std::int64_t value;
};

// --------------------
// Math functions
// --------------------
std::int64_t add(std::int64_t first, std::int64_t second)
{
    return first + second;
}

std::int64_t subtract(std::int64_t first, std::int64_t second)
{
    return first - second;
}

std::int64_t multiply(std::int64_t first, std::int64_t second)
{
    return first * second;
}

std::int64_t divide(std::int64_t first, std::int64_t second)
{
    if (second == 0)
    {
        return 0;  /// ?????
    }

    return first / second;
}

// --------------------
// Safe power function
// --------------------
std::int64_t power(Base base, Exponent exponent)
{
    if (exponent.value < 0)
    {
        return 0;  /////
    }

    std::int64_t result = 1;

    for (std::int64_t i = 0; i < exponent.value; ++i)
    {
        result *= base.value;
    }

    return result;
}

std::int64_t factorial(std::int64_t n)
{
    if (n < 0)
    {
        return 0;  // ??????
    }

    if (n == 0 || n == 1)
    {
        return 1;
    }

    std::int64_t prev = factorial(n - 1);

    return n * prev;
}

}  // namespace mathlib

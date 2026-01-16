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
std::int64_t add(std::int64_t first, std::int64_t second);
std::int64_t subtract(std::int64_t first, std::int64_t second);
std::int64_t multiply(std::int64_t first, std::int64_t second);
std::int64_t divide(std::int64_t first, std::int64_t second);
std::int64_t power(Base base, Exponent exponent);
std::int64_t factorial(std::int64_t n);

}  // namespace mathlib

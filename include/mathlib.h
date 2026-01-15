#pragma once
#include <cstdint>  // std::int64_t, std::uint8_t

namespace mathlib
{

enum class MathError : std::uint8_t
{
    None,
    DivisionByZero,
    NegativeFactorial,
    InvalidArgument
};

struct MathResult
{
    std::int64_t value;
    MathError error;
};

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
MathResult add(std::int64_t first, std::int64_t second);
MathResult subtract(std::int64_t first, std::int64_t second);
MathResult multiply(std::int64_t first, std::int64_t second);
MathResult divide(std::int64_t first, std::int64_t second);
MathResult power(Base base, Exponent exponent);
MathResult factorial(std::int64_t n);

}  // namespace mathlib

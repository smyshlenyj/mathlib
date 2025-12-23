#pragma once
#include <cstdint>  // std::uint64_t

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

MathResult add(std::int64_t first, std::int64_t second);
MathResult subtract(std::int64_t first, std::int64_t second);
MathResult multiply(std::int64_t first, std::int64_t second);
MathResult divide(std::int64_t first, std::int64_t second);
MathResult power(std::int64_t base, std::int64_t exponent);
MathResult factorial(std::int64_t n);

}  // namespace mathlib
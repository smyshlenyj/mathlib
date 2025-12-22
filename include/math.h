#pragma once
#include <cstdint>  // для std::uint64_t

namespace mathlib
{

enum class MathError 
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

MathResult add(int, int);
MathResult subtract(int, int);
MathResult multiply(int, int);
MathResult divide(int, int);
MathResult power(int, int);
MathResult factorial(int);

}  // namespace mathlib
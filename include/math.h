#pragma once
#include <cstdint>  // для std::uint64_t

namespace mathlib
{

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
int power(int, int);
std::uint64_t factorial(int);

}  // namespace mathlib
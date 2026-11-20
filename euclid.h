// euclid.h
// Header-only C++ library: HCF (GCD) and LCM using Euclid's algorithm.
// Usage:  #include "euclid.h"
//         euclid::gcd(12, 18);            -> 6
//         euclid::lcm({4, 6, 8, 10});     -> 120

#ifndef EUCLID_H
#define EUCLID_H

#include <cstdlib>
#include <initializer_list>
#include <stdexcept>
#include <vector>

namespace euclid {

// HCF of two numbers (iterative Euclid). Negative inputs are treated by absolute value.
// gcd(0, 0) returns 0.
inline long long gcd(long long a, long long b) {
    a = std::llabs(a);
    b = std::llabs(b);
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// HCF of two numbers (recursive Euclid). Same result as gcd().
inline long long gcdRecursive(long long a, long long b) {
    a = std::llabs(a);
    b = std::llabs(b);
    if (b == 0) return a;
    return gcdRecursive(b, a % b);
}

// LCM of two numbers. lcm(x, 0) returns 0.
// Divides before multiplying to reduce the chance of overflow.
inline long long lcm(long long a, long long b) {
    long long g = gcd(a, b);
    if (g == 0) return 0;
    return std::llabs(a) / g * std::llabs(b);
}

// HCF of many numbers: gcd(a,b,c) = gcd(gcd(a,b),c).
// Throws std::invalid_argument if the list is empty.
inline long long gcd(const std::vector<long long>& nums) {
    if (nums.empty()) throw std::invalid_argument("euclid::gcd: empty list");
    long long result = std::llabs(nums[0]);
    for (size_t i = 1; i < nums.size(); i++) result = gcd(result, nums[i]);
    return result;
}

// LCM of many numbers: lcm(a,b,c) = lcm(lcm(a,b),c).
// Throws std::invalid_argument if the list is empty.
inline long long lcm(const std::vector<long long>& nums) {
    if (nums.empty()) throw std::invalid_argument("euclid::lcm: empty list");
    long long result = std::llabs(nums[0]);
    for (size_t i = 1; i < nums.size(); i++) result = lcm(result, nums[i]);
    return result;
}

// Convenience overloads so you can write euclid::lcm({4, 6, 8}).
inline long long gcd(std::initializer_list<long long> nums) {
    return gcd(std::vector<long long>(nums));
}
inline long long lcm(std::initializer_list<long long> nums) {
    return lcm(std::vector<long long>(nums));
}

}  // namespace euclid

#endif  // EUCLID_H
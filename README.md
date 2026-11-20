# euclid.h

A lightweight, header-only C++ library for computing the **HCF (GCD)** and
**LCM** of two or more integers using **Euclid's algorithm**.

## Why use it?
- **Zero setup:** copy one file (`euclid.h`) and `#include` it. No build steps or dependencies.
- **Any number of inputs:** works with 2 numbers, a `{...}` list, or a `std::vector`.
- **Iterative and recursive versions** of Euclid's algorithm.
- **Safe by design:** handles negative numbers, zero, and empty lists, and divides before multiplying in LCM to reduce overflow.
- **Clean API:** everything lives in the `euclid::` namespace, so it won't clash with your code.

## Quick example
    #include "euclid.h"

    euclid::gcd(48, 36);            // 12
    euclid::lcm({4, 6, 8, 10});     // 120

## Good for
Simplifying fractions, finding common denominators, scheduling and
cycle problems, competitive programming, and learning how Euclid's
algorithm works.

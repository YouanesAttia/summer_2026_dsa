#include <iostream>

// x^n = x * x^(n-1)
// power(base, exp) = base * power(base, exp - 1)  if exp > 1
//                  = base                         if exp = 1
//                  = 1                            if exp = 0

long long power(long long base, int exp) // O(exp)
{
    if (exp == 0)
        return 1;

    if (exp == 1)
        return base;

    return base * power(base, exp - 1);
}

// x^n = (x²)^(n/2)                  if n is even
// x^n = x * (x²)^((n-1)/2)          if n is odd

// power(base, exp) = power(base * base, exp / 2)
//                                            if exp > 0 and exp is even
//
//                  = base * power(base * base, exp / 2)
//                                            if exp > 0 and exp is odd
//
//                  = 1
//                                            if exp = 0

long long power2(long long base, int exp) // O(log(exp))
{
    if (exp == 0)
        return 1;

    if (exp % 2 == 1)
        return base * power2(base * base, exp / 2);
    else
        return power2(base * base, exp / 2);
}
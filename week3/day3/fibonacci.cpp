#include <iostream>

// fibonacci(n) = fibonacci(n - 2) + fibonacci(n - 1) if n >= 2
//              = n                                   if n <= 1

// Excessive recursion
int fibonacci(int n) // ~ O(2^n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int F[100];
int fibonacci2(int n) // O(n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fibonacci2(n - 2);

        if (F[n - 1] == -1)
            F[n - 1] = fibonacci2(n - 1);

        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    std::fill(F, F + 100, -1);
}
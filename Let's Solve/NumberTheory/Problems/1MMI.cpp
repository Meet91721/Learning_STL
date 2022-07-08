/*
There are n children and k toffees. k < n
Count the number of ways to distribute the toffees
among n students such that each student gets 1 toffee
only
k < n < 1e6
Give ans in modulo M, M = 1e9+7
*/

// solution: nCk

#include <bits/stdc++.h>
const int M = 1e9 + 7;
using namespace std;
const int N = 1e6 + 7;
int fact[N];

void precomputeFact()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % M;
    }
}

int binExpo(int a, int b, int m)
{
    int res = 1;
    a = a % m;
    while (b)
    {
        if (b & 1)
        {
            res = (1LL * res * a) % m;
        }
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    precomputeFact();
    int n = 12, k = 2;
    int numerator = fact[n];
    int denominator = ((fact[n - 1] % M) * (fact[2] % M)) % M;
    // Finding MMI of denominator
    // Note that M is prime hence using fermat's little theorem
    // Exponent of M-2
    denominator = binExpo(denominator, M - 2, M);
    int result = ((numerator % M) * (denominator % M)) % M;
}
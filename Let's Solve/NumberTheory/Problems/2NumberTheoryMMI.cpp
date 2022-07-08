// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

#include <bits/stdc++.h>
const int M = 1e9 + 7;
const int N = 1e6 + 10;
using namespace std;
int fact[N];

int binExpo(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (1LL * a * res) % m;
        }
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % M;
    }
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int numerator = fact[k];
        // numerator = (1LL*(fact[n]%M)*fact[k])%M;
        int denominator = fact[k - n];
        denominator = binExpo(denominator, M - 2, M);
        cout << (1LL * (numerator % M) * (denominator % M)) % M << '\n';
    }
}
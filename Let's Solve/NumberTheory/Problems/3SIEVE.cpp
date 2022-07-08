// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/

#include <bits/stdc++.h>

const int N = 1e6 + 10;
using namespace std;

int hsh[N];

int multiples[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }
    multiples[1] = n;
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            multiples[i] += hsh[j];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        long int res = multiples[p] + multiples[q];
        long long int lcm = (1LL * q * p) / __gcd(p, q);
        if (lcm < N)
            res -= multiples[lcm];
        cout << res << '\n';
    }
}
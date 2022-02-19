#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> mp;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
    {
        return 1;
    }
    auto it = mp.find(n);
    if (it == mp.end())
    {
        mp[n] = fib(n - 1) + fib(n - 2);
        return mp[n];
    }
    else
    {
        return mp[n];
    }
}

int32_t main()
{
    cout << "Fib sequence from 1 to 49 ";
    for (int i = 0; i < 50; i++)
    {
        cout << i << "\t" << fib(i) << endl;
    }
}

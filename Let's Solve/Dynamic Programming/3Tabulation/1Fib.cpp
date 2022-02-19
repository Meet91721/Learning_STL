#include <bits/stdc++.h>
#define int long long
using namespace std;

int fib[100000 + 1];

void fibFunc()
{
    for (int i = 0; i < 100000 - 1; i++)
    {
        fib[i + 1] += fib[i];
        fib[i + 2] += fib[i];
    }
}
int32_t main()
{
    fib[1] = 1;
    fibFunc();
    for (int i = 0; i < 51; i++)
    {
        cout << i << "\t" << fib[i] << endl;
    }
}

// Time Complexity O(n)
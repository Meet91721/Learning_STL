// Just observe the sequence of continuous xorred elements
// Pattern helps optimize the code almost to O(1) for finding xor from 1 to n

#include <bits/stdc++.h>
using namespace std;

int funcc(int a)
{
    int xxor = 0;
    if (a < 4)
    {
        for (int i = 1; i <= a; i++)
        {
            xxor ^= i;
        }
    }
    else
    {
        int t = (a + 1) % 4;
        for (int i = 1; i <= t; i++)
        {
            xxor ^= (a + 1 - i);
        }
    }
    return xxor;
}

int main()
{
    int xxor = 0;
    for (int i = 0; i < 10000; i++)
    {
        xxor ^= i;
        if (xxor != funcc(i))
        {
            cout << "Invalid";
            break;
        }
        else
        {
            cout << xxor << '\t' << funcc(i) << '\n';
        }
    }
}
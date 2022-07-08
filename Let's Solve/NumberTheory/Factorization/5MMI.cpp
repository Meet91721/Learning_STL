// Modular multiplicative inverse

// (a+b)%M = ((a%M)+(b%M))%M
// (a*b)%M = ((a%M)*(b%M))%M
// (a-b)%M = ((a%M)-(b%M)+M)%M
// (a/b)%M = (a*b^-1)%M
/*
    where b^-1 is MMI of a
    MMI definition:
    (a*b)%M=1
    b=(a^(m-2))%M       find using binary exponentiation
*/
#include <bits/stdc++.h>

using namespace std;
const int M = 1e9 + 7;

int binExp(int a, int b, int m)
{
    int res = 1;
    // a = a % m;
    while (b)
    {
        if (b & 1)
        {
            res = (1LL * a * res) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout << "MMI of 2: ";
    cout << binExp(2, M - 2, M);
}
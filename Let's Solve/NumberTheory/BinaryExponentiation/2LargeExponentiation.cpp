/*
Previous method had some limitations about constraints of a,b,M
This method will work if a or M will violate those constraints
Note that this method is also not sufficient for b violating those constraints
*/

#include <bits/stdc++.h>

using namespace std;
const long long int M = 1e18 + 7;

// Now this has time complexity of O((log(N))^2)
int iterativeBinPower(long a, int b)
{
    a = a % M; // Constraints for a satisfied
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = iterativeBinMultiplier(res, a);
        }
        a = iterativeBinMultiplier(a, a);
        b >>= 1;
    }
    return res;
}

// If constraints on M are <=10^18
// Simple multiplication cannot be calculated(since `a` will soon overflow)
// Hence binary multiplication of a is done, where in every step %M is calculated
// So that the multiplication cannot overflow
int iterativeBinMultiplier(long long a, long long b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}
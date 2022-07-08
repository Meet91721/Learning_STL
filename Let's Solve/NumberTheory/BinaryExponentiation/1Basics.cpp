// Calculate power in log n complexity
#include <bits/stdc++.h>
using namespace std;
// Note that this code works only for the following constraints:
// a <= 10^9, b <= 10^9, M <= 10^9
// For problems violating constraints prefer the next code :)

const int M = 1e9 + 7;

// calculates a^b using recursive approach
int recursiveBinPower(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int res = recursiveBinPower(a, b / 2);
    if (b & 1)
        return (a * 1LL * (1LL * res * res) % M) % M;
    return (res * res * 1LL) % M;
}

// calculates a^b using iterative appraoch
// iterations are generally better than recursions
int iterativeBinPower(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (1LL * res * a) % M;
        }
        a = (1LL * a * a) % M;
        b >>= 1;
    }
    return res;
    /*
    WORKING
    B = (13)10 = (1101)2
    A = 3
    RES = 1
        B           A               RES
        1101        (3^1)           3^1
        110         (3^2)           3^1
        11          (3^4)           3^5
        1           (3^8)           3^13
        0           HALT            HALT
    */
}

int main()
{
    int a = 2;
    int b = 13;
    cout << recursiveBinPower(a, b) << '\n';
    cout << iterativeBinPower(a, b) << '\n';
}
#include <bits/stdc++.h>
using namespace std;

float nthRoot(float n, int root)
{
    // precision: 0.1
    float lo = 0, hi = n;
    // float power = 1 / root;
    while (hi - lo > 0.1)
    {
        float mid = (hi + lo) / 2;
        // cout << hi << " " << lo << " " << mid << " " << pow(mid, root) << " " << n << '\n';
        if (pow(mid, root) > n)
        {
            hi = mid - 0.1;
        }
        else if (pow(mid, root) < n)
        {
            lo = mid + 0.1;
        }
        else
        {
            return mid;
        }
    }
    return lo;
}

int main()
{
    cout << nthRoot(4, 2) << '\n';
    cout << nthRoot(9, 3) << '\n';
    cout << nthRoot(8, 3) << '\n';
}
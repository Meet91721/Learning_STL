// https://www.hackerrank.com/challenges/and-product/problem

#include <bits/stdc++.h>

#define int long long
using namespace std;
int32_t main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long a, b, res = 0;
        cin >> a >> b;
        for (int i = 31; i >= 0; i--)
        {
            int t1 = (a & (1 << i)) ? 1 : 0;
            int t2 = (b & (1 << i)) ? 1 : 0;
            if (t1 == t2)
            {
                res += t1 * pow(2, i);
            }
            else
                break;
        }
        cout << res << endl;
    }
}
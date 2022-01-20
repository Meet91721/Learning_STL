// https://www.hackerrank.com/challenges/sansa-and-xor/problem
#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (n % 2 == 0)
        {
            cout << "0\n";
            continue;
        }
        int res = 0;
        for (int i = 0; i <= (n); i += 2)
        {
            res = res ^ arr[i];
        }
        cout << res << endl;
    }
}
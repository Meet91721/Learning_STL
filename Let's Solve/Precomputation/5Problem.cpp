// https://www.codechef.com/problems/GCDQ

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int arr[n + 1];
        arr[0] = 1;
        int forw[n + 1], back[n + 2];
        forw[0] = 0;
        back[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            forw[i] = __gcd(arr[i], forw[i - 1]);
        }
        for (int i = n; i >= 1; i--)
        {
            back[i] = __gcd(arr[i], back[i + 1]);
        }

        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(forw[l - 1], back[r + 1]) << endl;
        }
    }
    // O(T * (N + N)) ~ 10^6
}
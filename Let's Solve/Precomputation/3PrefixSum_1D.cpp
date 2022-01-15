/*
Given array a of N integers. Given Q queries
and in each query given L and R print sum of
array elements from L to R(L, R included)

Constraints:
1 <= N <= 10^5
1 <= a[i] <= 10^9
1 <= Q <= 10^5
1 <= L,R <= N
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
long long int a[N];
int main()
{
    /*
        Consider taking 1 base array whenever
        such question is asked
    */
    /*
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            long long sum = 0;
            for (int i = l; i <= r; i++)
            {
                sum += a[i];
            }
            cout << sum << endl;
        }
        // O(N) + O(q * N)~ 10^10
    */

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long temp;
        cin >> temp;
        a[i] = a[i - 1] + temp;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
    // O(N) + O(Q) ~ 10^5
}
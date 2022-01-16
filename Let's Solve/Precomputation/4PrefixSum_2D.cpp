/*
Given 2d array a of N*N integers. Given Q
queries and in each query given a, b, c and d
print sum of square represented by (a, b) as
top left point and (c, d) as bottom right
point

Constraints:
1 <= N <= 10^3
1 <= a[i][j] <= 10^9
1 <= Q <= 10^5
1 <= a, b, c, d <=N
*/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
long long pf[N][N];
int main()
{
    /*
        int n;
        cin >> n;
        // Make sure to declare the array of index + 1
        // when dealing with base 1
        long long int arr[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
            }
        }

        int q;
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            long long sum = 0;
            for (int j = a; j <= c; j++)
            {
                for (int k = b; k <= d; k++)
                {
                    sum += arr[j][k];
                }
            }
            cout << sum << endl;
        }
        // O(N^2) + O(Q*N^2) 10^12
    */
    int n;
    cin >> n;
    long long int arr[n + 1][n + 1];
    // long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            pf[i][j] = arr[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << pf[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (pf[c][d] - pf[a - 1][d] - pf[c][b - 1] + pf[a - 1][b - 1]) << endl;
    }
    // O(N^2) + O(Q) ~ 10^6
}
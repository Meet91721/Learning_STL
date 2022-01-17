// https://www.hackerrank.com/challenges/crush/problem
#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 10;
long long int arr[N];

int main()
{
    /*
        int n, m;
        cin >> n >> m;
        int arr1[n] = {0};
        for (int i = 0; i < m; i++)
        {
            long long int a, b, k;
            cin >> a >> b >> k;
            for (int i = a; i <= b; i++)
            {
                arr1[i] += k;
            }
        }
        int max = arr1[0];
        for (int i = 0; i < n; i++)
        {
            if (max < arr1[i])
            {
                max = arr1[i];
            }
        }
        cout << max;
        // O(m*n+n) ~ 10^12
    */
    long long int n, m;
    cin >> n >> m;
    for (long int i = 0; i < m; i++)
    {
        long long int a, b, k;
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b + 1] -= k;
    }

    long long int max = arr[1];
    for (long long int i = 1; i <= n; i++)
    {
        arr[i] += arr[i - 1];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << max;
}
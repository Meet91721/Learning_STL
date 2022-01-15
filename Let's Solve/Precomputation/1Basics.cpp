/*
Given T test cases and in each test case
a number N. Print its factorial for each test case %M
where M = 10^0+7

Constraints
1 <= T <= 10^5
1 <= N <= 10^5
*/

#include <bits/stdc++.h>
const int M = 1e9 + 7;
const int N = 1e5 + 10;

using namespace std;
int main()
{
    /*
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            long long fact = 1;
            for (int i = 1; i <= n; i++)
            {
                fact = (fact * i) % M;
            }
            cout << fact << endl;
        }
        // This has O(T*N) time conplexity
        // This is close to 10 ^ 10 TLE
    */
    long long fact[N];
    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }
    // NewComplexity: O(N+t)
}
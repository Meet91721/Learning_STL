// https://atcoder.jp/contests/dp/tasks/dp_d

// SHREE
#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[110][100010];

long long func(int ind, int val, vector<vector<int>> &vec)
{
    if (val == 0)
        return 0;
    if (ind < 0)
        return 1e15;
    if (dp[ind][val] != -1)
        return dp[ind][val];
    int res = func(ind - 1, val, vec);
    if (val - vec[ind][1] >= 0)
        res = min(res, func(ind - 1, val - vec[ind][1], vec) + vec[ind][0]);
    return dp[ind][val] = res;
}

int32_t main()
{
    int n, w;
    cin >> n >> w;
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> vec(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i][0] >> vec[i][1];
    }
    int ans = 1e5 + 10;
    for (int i = ans; i >= 0; i--)
    {
        if (func(n - 1, i, vec) <= w)
        {
            cout << i;
            break;
        }
    }
}

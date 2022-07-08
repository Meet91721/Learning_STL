// https: // atcoder.jp/contests/dp/tasks/dp_e

// SHREE
#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[101][100001];

long long func(int ind, int wt, vector<vector<int>> &vec)
{

    if (wt == 0)
        return 0;
    if (ind < 0)
        return 0;
    if (dp[ind][wt] != -1)
        return dp[ind][wt];
    int res = func(ind - 1, wt, vec);
    if (wt - vec[ind][0] >= 0)
        res = max(res, func(ind - 1, wt - vec[ind][0], vec) + vec[ind][1]);
    dp[ind][wt] = res;
    return res;
}

int32_t main()
{
    int n, w;
    cin >> n >> w;
    vector<vector<int>> vec(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i][0] >> vec[i][1];
    }
    memset(dp, -1, sizeof(dp));
    cout << func(n - 1, w, vec);
}

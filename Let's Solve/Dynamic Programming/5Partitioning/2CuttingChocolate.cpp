// https://www.codingninjas.com/codestudio/problems/cost-to-cut-a-chocolate_3208460?
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int recurse(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;
    if (dp[i][j])
        return dp[i][j];
    int t = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        t = min(t, cuts[j + 1] - cuts[i - 1] + recurse(i, ind - 1, cuts) + recurse(ind + 1, j, cuts));
    }
    return dp[i][j] = t;
}

int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    for (int i = 0; i <= c; i++)
        for (int j = 0; j <= c; j++)
            dp[i][j] = 0;
    cuts.push_back(n);
    cuts.push_back(0);
    sort(cuts.begin(), cuts.end());
    return recurse(1, cuts.size() - 2, cuts);
}
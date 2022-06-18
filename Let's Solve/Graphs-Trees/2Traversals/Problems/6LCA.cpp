// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];

vector<int> v[2];
int dfs(int n, int toFind, int index, int prnt = -1)
{
    if (n == toFind)
    {
        v[index].push_back(n);
        return 1;
    }
    for (int child : g[n])
    {
        if (child == prnt)
            continue;
        if (dfs(child, toFind, index, n) == 1)
        {
            v[index].push_back(n);
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << "Enter the first number to find ancestor of: ";
    int x, y;
    cin >> x;
    cout << "Enter the second number to find ancestor of: ";
    cin >> y;
    dfs(1, x, 0);
    reverse(v[0].begin(), v[0].end());
    for (auto child : v[0])
    {
        cout << child << " ";
    }
    cout << endl;
    dfs(1, y, 1);
    reverse(v[1].begin(), v[1].end());
    for (auto child : v[1])
    {
        cout << child << " ";
    }
    cout << endl;
    int i = 0;

    for (i = 0; i < min(v[1].size(), v[0].size()); i++)
    {
        if (v[1][i] != v[0][i])
            break;
    }

    cout << "Lowest common ancestor is: " << v[1][i - 1];
}

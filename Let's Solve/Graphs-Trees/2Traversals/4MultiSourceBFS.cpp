// https://www.codechef.com/problems/SNSOCIAL

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int vis[N][N];
int val[N][N];
int lev[N][N];
int n, m;

vector<pair<int, int>> movements = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

bool isValid(int x, int y)
{
    return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

int BFS()
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == mx)
            {
                q.push({i, j});
                // cout << i << " " << j << '\n';
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    // while(!q.empty()){
    // 	cout << q.front().first << " " << q.front().second << '\n';
    // 	q.pop();
    // }
    int res = 0;
    while (!q.empty())
    {
        auto v = q.front();
        q.pop();
        int v_x = v.first;
        int v_y = v.second;
        for (auto movement : movements)
        {
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if (!isValid(child_x, child_y))
                continue;
            if (vis[child_x][child_y])
                continue;
            q.push({child_x, child_y});
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = 1;
            res = max(res, lev[child_x][child_y]);
        }
    }
    return res;
}

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
            val[i][j] = INF;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }
        cout << BFS() << '\n';
    }
}
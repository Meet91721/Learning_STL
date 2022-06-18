#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int vis[9][9];
int lev[9][9];

int getX(string s)
{
    return s[1] - '1';
}
int getY(string s)
{
    return s[0] - 'a';
}

vector<pair<int, int>> allPositions = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x > 7 || y > 7)
    {
        return false;
    }
    return true;
}

int BFS(int startX, int startY, int destX, int destY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    vis[startX][startY] = 1;
    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        int x = v.first, y = v.second;
        for (auto movement : allPositions)
        {
            int childX = x + movement.first;
            int childY = y + movement.second;
            if (!isValid(childX, childY))
                continue;
            if (!vis[childX][childY])
            {
                q.push({childX, childY});
                lev[childX][childY] = lev[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
    }
    return lev[destX][destY];
}

void reset()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            vis[i][j] = 0;
            lev[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        string start, destination;
        cin >> start >> destination;
        int startX = getX(start);
        int startY = getY(start);
        int destX = getX(destination);
        int destY = getY(destination);
        cout << BFS(startX, startY, destX, destY) << '\n';
    }
}
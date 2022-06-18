// https://www.codechef.com/problems/REVERSE

// No need of visited array in zeroone BFS
// dequeue is used instead of queue

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

// Representation of weighted graph
// stores node and weight
vector<pair<int, int>> g[N];

// Level array / Distance array usually initialized with INF in 01BFS
vector<int> lev(N, INF);
int n, m;

int BFS()
{
    deque<int> q;
    q.push_back(1);
    lev[1] = 0;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();

        for (auto child : g[cur_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (lev[cur_v] + wt < lev[child_v])
            {
                lev[child_v] = lev[cur_v] + wt;
                if (wt)
                {
                    q.push_back(child_v);
                }
                else
                {
                    q.push_front(child_v);
                }
            }
        }
    }
    return lev[n] == INF ? -1 : lev[n];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    cout << BFS() << '\n';
}
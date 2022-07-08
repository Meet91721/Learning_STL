// https://www.eolymp.com/en/problems/1453

// Dijkstra fails when negative weights are present
// BellmanFord fails when there is negative weight cycle
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> distance(n + 1, 30000);
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    distance[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (distance[edges[j][0]] == 30000)
                continue;
            distance[edges[j][1]] = min(distance[edges[j][0]] + edges[j][2], distance[edges[j][1]]);
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        cout << distance[i] << " ";
    }
}
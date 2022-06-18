#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    // n->Vertices, m->Edges
    cin >> n >> m;

    // destination, weight
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        // From To Weight
        int a, b, wt;
        cin >> a >> b >> wt;
        g[a].push_back({b, wt});
    }
    // Weight, Destination
    set<pair<int, int>> priorityQ;
    priorityQ.insert({0, 1});

    vector<int> distance(n + 1, INT_MAX);
    vector<bool> vis(n + 1, false);

    while (priorityQ.size() > 0)
    {
        auto &[wt, dst] = *priorityQ.begin();
        priorityQ.erase(priorityQ.begin());
        distance[dst] = min(distance[dst], wt);
        if (vis[dst])
            continue;
        vis[dst] = true;
        for (int i = 0; i < g[dst].size(); i++)
        {
            priorityQ.insert({wt + g[dst][i].second, g[dst][i].first});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t" << distance[i] << '\n';
    }
}
// Time Complexity: O(ElogV) OR O(ElogE)

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int parent[N];

void MAKE(int n)
{
    parent[n] = n;
}

int FIND(int n)
{
    if (parent[n] == n)
        return n;
    return parent[n] = FIND(parent[n]);
}

void UNION(int a, int b)
{
    a = parent[a];
    b = parent[b];
    if (a == b)
        return;
    parent[b] = a;
}

int main()
{
    // n->Nodes, m->Edges
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        MAKE(i);
    }

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        // edge, edge, wt
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    for (int i = 1; i <= n; i++)
        MAKE(i);

    sort(edges.begin(), edges.end());

    int total_cost = 0;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (FIND(u) == FIND(v))
            continue;
        UNION(u, v);
        total_cost += wt;
        cout << u << " " << v << '\n';
    }
    cout << total_cost << '\n';
}

/*
INPUT
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
OUTPUT:
1 4
1 2
3 2
5 1
2 6
17
*/
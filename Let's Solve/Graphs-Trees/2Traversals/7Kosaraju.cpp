// https://www.codingninjas.com/codestudio/problems/985311?

#include <bits/stdc++.h>

using namespace std;

vector<int> topo;

void dfs(int node, vector<vector<int>> &g, vector<int> &vis)
{
    vis[node] = 1;
    for (int i = 0; i < g[node].size(); i++)
    {
        if (vis[g[node][i]])
            continue;
        dfs(g[node][i], g, vis);
    }
    topo.push_back(node);
}
vector<int> kosa;
void kosaraju(int node, vector<vector<int>> &transpose, vector<int> &vis)
{
    //     vector<int>ret;
    //     cout << node << "\n";
    kosa.push_back(node);
    vis[node] = 1;
    for (int i = 0; i < transpose[node].size(); i++)
    {
        if (vis[transpose[node][i]])
            continue;
        kosaraju(transpose[node][i], transpose, vis);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    topo.clear();
    vector<vector<int>> g(n);
    vector<vector<int>> transposeG(n);
    for (int i = 0; i < edges.size(); i++)
    {
        g[edges[i][0]].push_back(edges[i][1]);
        transposeG[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        dfs(i, g, vis);
    }

    //     for(int i = 0; i < n; i++)
    //         cout << topo[i] << " ";
    //     cout << '\n';

    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (vis[topo[i]])
            continue;
        kosaraju(topo[i], transposeG, vis);
        //         cout << "SIZE" << kosa.size() << '\n';
        res.push_back(kosa);
        kosa.clear();
    }
    return res;
}
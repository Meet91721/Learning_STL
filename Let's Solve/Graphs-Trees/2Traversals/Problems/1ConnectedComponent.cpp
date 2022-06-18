// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int visited[N];

void DFS(int index)
{
    // cout << index << " ";
    for (int i : graph[index])
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            DFS(i);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            count++;
            visited[i] = 1;
            DFS(i);
        }
    }
    cout << count;
}
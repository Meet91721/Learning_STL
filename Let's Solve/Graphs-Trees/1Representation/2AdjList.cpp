#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> graph[N];

int main()
{
    int n, m;
    // n -> vertices
    // m -> edges
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // Connectedness
    int i, j;
    cin >> i >> j;
    for (int child : graph[i])
    {
        if (child == j)
        {
            cout << "Connected\n";
        }
    }

    // Disadvantages:
    // Checking Connections and weight takes O(N)
}

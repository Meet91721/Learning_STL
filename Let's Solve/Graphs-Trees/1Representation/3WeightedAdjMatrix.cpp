#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int graph[N][N];

int main()
{
    int n, m;
    // n -> vertices
    // m -> edges
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        // wt -> weight
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }
}

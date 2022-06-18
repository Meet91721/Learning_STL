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
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    // Checking connectedness
    int i, j;
    cin >> i >> j;
    if (graph[i][j] == 1)
    {
        cout << "Connected\n";
    }

    // Problems:
    // O(N^2) - Space Complexity
    // N = 10 ^ 5

    // Advantages:
    // i, j are connected? weight of i, j?  ==> TimeComplexity: O(1)
}

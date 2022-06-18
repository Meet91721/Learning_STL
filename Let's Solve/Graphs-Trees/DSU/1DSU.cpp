// DISJOINT SET UNION
/*
3 main functions:
    1) make: creates new node
    2) find: returns root node of the group
    3) union: unions 2 groups/nodes
*/

// Time complexity: O(aplha(n)) amortarized time complexity         Almost constant
// Inverse Ackerman     (That's what she said)

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int Find(int v)
{
    if (v == parent[v])
        return v;
    // Path compressions
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        // Union by size
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        size[a] += size[b];
        parent[b] = a;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    // Finding size for j
    int j;
    cin >> j;
    Find(j);
    cout << "Size of group where j is present is: " << size[parent[j]];

    // Counting number of connected components
    int connected_ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Find(i) == i)
        {
            connected_ct++;
        }
    }
}

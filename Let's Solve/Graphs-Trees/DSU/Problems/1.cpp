// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

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

void UNION(int i, int j)
{
    i = FIND(i);
    j = FIND(j);
    parent[j] = i;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        MAKE(i);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        UNION(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        FIND(i);
    }
    unordered_set<int> s;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << '\n';
        s.insert(parent[i]);
    }
    cout << s.size();
}
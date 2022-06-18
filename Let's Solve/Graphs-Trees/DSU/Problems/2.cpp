// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/

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
    a = FIND(a);
    b = FIND(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int e[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        cin >> e[i];
    }
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++)
        MAKE(i);
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        UNION(a, b);
    }
    for (int i = 1; i <= n; i++)
        FIND(i);

    // <parent town, <min risk, count with min risk>>
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int prnt = parent[i];
        auto it = mp.find(prnt);
        if (it == mp.end())
        {
            mp[prnt] = {e[i], 1};
            continue;
        }
        auto &[risk, cnt] = mp[prnt];
        if (risk < e[i])
            continue;
        if (risk == e[i])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
            risk = e[i];
        }
    }
    int res = 1;
    for (auto it : mp)
    {
        res = (res * (it.second.second) % M) % M;
    }
    cout << res;
}
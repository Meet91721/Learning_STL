// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int SIZE[N];
int parent[N];
multiset<int> s;

void MAKE(int i)
{
    parent[i] = i;
    s.insert(1);
    SIZE[i] = 1;
}

int FIND(int n)
{
    if (parent[n] == n)
        return n;
    parent[n] = FIND(parent[n]);
    return parent[n];
}

void UNION(int a, int b)
{
    a = FIND(a);
    b = FIND(b);
    if (a == b)
        return;
    parent[b] = a;
    auto it = s.find(SIZE[a]);
    s.erase(it);
    it = s.find(SIZE[b]);
    s.erase(it);
    SIZE[a] += SIZE[b];
    s.insert(SIZE[a]);
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        MAKE(i);
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        UNION(a, b);
        auto it = s.end();
        it--;
        cout << *it - *(s.begin()) << '\n';
    }
}
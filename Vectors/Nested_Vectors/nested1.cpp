#include <bits/stdc++.h>
using namespace std;
// VECTOR OF PAIRS

void print(vector<pair<int, int>> &v)
{
    cout << "Size of vectors: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << '\t' << v[i].second << "\n";
    }
    cout << endl;
}
int main()
{
    vector<pair<int, int>> p = {{1, 2}, {1, 3}, {3, 4}, {6, 7}};
    print(p);

    // 2 methods of Initializing
    int x = 9, y = 12;
    p.push_back({x, y});
    p.push_back(make_pair(x, y));
    print(p);
}
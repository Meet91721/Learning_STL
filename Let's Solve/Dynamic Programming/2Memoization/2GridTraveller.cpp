// Say that you are a traveller on a 2 grid. You begin in the
// top-left corner and your goal is to travel to the bottom right
// corner. You may only move down or right.

// In how many ways can you travel to the goal
// if you have a grid with dimensions m * n?

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<pair<int, int>, int> mp;

int gridTraveller(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    // if (n == 2 || m == 2)
    //     return 2;
    auto it = mp.find({n, m});
    if (it == mp.end())
    {
        mp[{n, m}] = gridTraveller(n - 1, m) + gridTraveller(n, m - 1);
        return mp[{n, m}];
    }
    return mp[{n, m}];
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << gridTraveller(n, m) << endl;
    }
}

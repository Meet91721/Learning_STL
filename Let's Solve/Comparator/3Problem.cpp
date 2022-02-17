// https://codeforces.com/contest/1575/problem/A

// SHREE
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool should_i_swap(pair<string, int> a, pair<string, int> b)
{
    string s1 = a.first;
    string s2 = b.first;

    int size = s1.length();
    for (int i = 0; i < size; i++)
    {
        if (i & 1)
        {
            if (s1[i] > s2[i])
                return true;
            else if (s2[i] > s1[i])
                return false;
        }
        else
        {
            if (s1[i] < s2[i])
                return true;
            else if (s2[i] < s1[i])
                return false;
        }
    }
    return true;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first;
        vec[i].second = i + 1;
    }
    sort(vec.begin(), vec.end(), should_i_swap);

    for (int i = 0; i < n; i++)
    {
        cout << vec[i].second << " \n"[i == n - 1];
    }
}

// Nothing much just a basics of how a comparator functions contributes

#include <bits/stdc++.h>

using namespace std;

bool should_i_swap(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        if (a.first > b.first)
            return true;
        return false;
    }
    if (a.second < b.second)
        return true;
    return false;
}

int main()
{
    vector<pair<int, int>> a(6);
    a[0].first = 4, a[0].second = 3;
    a[1].first = 5, a[1].second = 5;
    a[2].first = 5, a[2].second = 3;
    a[3].first = 25, a[3].second = 6;
    a[4].first = 7, a[4].second = 9;
    a[5].first = 8, a[5].second = 5;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (should_i_swap(a[i], a[j]))
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
}
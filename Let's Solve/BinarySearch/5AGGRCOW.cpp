// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
#define int long long
using namespace std;

bool predicate(vector<int> vec, int dist, int c)
{
    int i = 1;
    int index = 1;
    int lastIndex = 0;
    // bool res = false;
    while (i != c && index != vec.size())
    {
        // cout << "HERE IS i: " << i << '\t';
        // cout << index << " " << lastIndex << " " << vec[index] << " " << vec[lastIndex] << "\n";
        if (vec[index] - vec[lastIndex] >= dist)
        {
            lastIndex = index;
            index++;
            i++;
        }
        else
        {
            index++;
        }
    }
    if (i == c)
    {
        return true;
    }
    return false;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());

        int lo = 0, hi = vec[n - 1];
        while (hi - lo > 1)
        {
            int mid = (hi + lo) / 2;
            if (predicate(vec, mid, c))
            {
                lo = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (predicate(vec, hi, c))
        {
            cout << hi << '\n';
        }
        else
        {
            cout << lo << '\n';
        }
    }
}

// 1 2 4 8 9
//
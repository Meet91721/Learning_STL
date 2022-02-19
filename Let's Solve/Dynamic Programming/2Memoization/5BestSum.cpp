// Write a function `bestSum(targetSum, numbers)` that takes in a
// targetSum and an array of numbers as an arguments

// The function should return an array containing the shortest
// combination of numbers that add upto exactly the targetSum.

// If there is any tie for the shortest combinations you can return
// any of the combination

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, vector<int>> mp;
vector<int> bestSum(int n, int number[], int size)
{
    // cout << n << endl;
    if (n < 0)
    {
        return {-1};
    }
    if (n == 0)
    {
        return {};
    }

    auto it = mp.find(n);
    if (it != mp.end())
    {
        return mp[n];
    }

    vector<vector<int>> res;
    for (int i = 0; i < size; i++)
    {
        vector<int> v = bestSum(n - number[i], number, size);
        if (v.size() == 0)
        {
            v.push_back(number[i]);
            res.push_back(v);
            mp[n] = v;
        }
        else if (v[0] != -1)
        {
            v.push_back(number[i]);
            res.push_back(v);
            mp[n] = v;
        }
    }
    int min = INT_MAX;
    vector<int> rr = {-1};
    for (int i = 0; i < res.size(); i++)
    {
        if (min > res[i].size() && res[i][0] != -1)
        {
            min = res[i].size();
            rr = res[i];
        }
    }
    return rr;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        int n, q;
        cin >> n >> q;
        int arr[q];
        for (int i = 0; i < q; i++)
        {
            cin >> arr[i];
        }
        vector<int> v = bestSum(n, arr, q);

        if (v[0] == -1)
            cout << "[]" << '\n';
        else
        {
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}

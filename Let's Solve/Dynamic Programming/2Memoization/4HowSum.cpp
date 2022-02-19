// Write a function `howSum(targetSum, numbers)` that takes in a
// targetSum and an arrayof numbers as an arguments

// The function should return an array containing any combination of
// elements that add up to exactly the targetSum. If there is no
// combination that adds upto the targetSum, then return null

// For multiple possible combinations, return any one of them

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, pair<bool, vector<int>>> mp;

bool howSum(int targetSum, int numbers[], int size, vector<int> &res)
{
    if (targetSum < 0)
        return false;
    if (targetSum == 0)
    {
        return true;
    }
    auto it = mp.find(targetSum);
    if (it == mp.end())
    {

        bool temp = false;
        for (int i = 0; i < size; i++)
        {
            if (howSum(targetSum - numbers[i], numbers, size, res))
            {
                res.push_back(numbers[i]);
                return true;
            }
        }
        vector<int> r1;
        mp.insert({targetSum, {false, r1}});
        return false;
    }
    else
    {
        if (mp[targetSum].first == false)
            return false;
        res.insert(res.end(), mp[targetSum].second.begin(), mp[targetSum].second.end());
        return true;
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        int tgtsum, n;
        cin >> tgtsum;
        cin >> n;
        int arr[n];
        vector<int> res;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool t = howSum(tgtsum, arr, n, res);
        int s = res.size();
        if (t)
        {
            if (s == 0)
                cout << "No element needed\n";
            else
            {
                cout << "The possible cobination is: \n";
                for (int i = 0; i < s; i++)
                {
                    cout << res[i] << " \n"[i == s - 1];
                }
            }
        }
        else
        {
            cout << "No combination possible\n";
        }
    }
}
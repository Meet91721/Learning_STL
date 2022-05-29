// Implementation of lower bound and upper bound
#include <bits/stdc++.h>

using namespace std;

int lower_bound(vector<int> vec, int target)
{
    int lo = 0, hi = vec.size() - 1;
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (vec[mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    // cout << lo << " " << hi << '\n';
    if (vec[lo] >= target)
    {
        return lo;
    }
    else if (vec[hi] >= target)
    {
        return hi;
    }
    else
    {
        return -1;
    }
}

int upper_bound(vector<int> vec, int target)
{
    int lo = 0, hi = vec.size() - 1;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (vec[mid] > target)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (vec[lo] > target)
    {
        return lo;
    }
    if (vec[hi] > target)
    {
        return hi;
    }
    return -1;
}

int main()
{
    vector<int> arr;
    arr = {5, 5, 5, 7, 7, 8, 8};
    cout << lower_bound(arr, 6) << '\n';
    cout << lower_bound(arr, 7) << '\n';
    cout << lower_bound(arr, 8) << '\n';
    cout << lower_bound(arr, 3) << '\n';
    // cout << *upper_bound(arr.begin(), arr.end(), 1) << '\n';
    cout << upper_bound(arr, 6) << '\n';
    cout << upper_bound(arr, 7) << '\n';
    cout << upper_bound(arr, 8) << '\n';
    cout << upper_bound(arr, 3) << '\n';
}
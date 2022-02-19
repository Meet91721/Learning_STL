// Write a function `canSum(targetSum, numbers)` that takes in a
// targetSum and an arrayof numbers as an arguments

// The function should return a boolean indicating whether or not it
// is possible to generate the targetSum using numbers from the array.

// You may use an element of the array as many times as needed
// You may assume that all inputs are nonnegative

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<int, bool> mp;

bool canSum(int targetSum, int number1[], int size)
{
    if (targetSum < 0)
        return false;
    if (targetSum == 0)
        return true;
    auto it = mp.find(targetSum);
    if (it != mp.end())
    {
        return mp[targetSum];
    }
    bool res = false;
    for (int i = 0; i < size; i++)
    {
        res = res | canSum(targetSum - number1[i], number1, size);
        if (res)
            return res;
    }
    return res;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int tgtsum;
        cin >> tgtsum;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << (canSum(tgtsum, arr, n) ? "It is possible\n" : "It is not possible");
    }
}
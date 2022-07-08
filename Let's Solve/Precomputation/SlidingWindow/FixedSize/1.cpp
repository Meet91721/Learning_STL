/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

Example:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
4 2
100 200 300 400

Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
*/

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int s = accumulate(arr.begin(), arr.begin() + k, 0);
    int maxS = s;
    int l = 0, r = k - 1;
    r++;
    l++;
    while (r < n)
    {
        s += arr[r];
        s -= arr[l - 1];
        r++;
        l++;
        if (s > maxS)
            maxS = s;
    }
    cout << maxS << '\n';
}
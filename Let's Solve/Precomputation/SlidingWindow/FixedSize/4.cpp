// https://www.interviewbit.com/problems/sliding-window-maximum/

#include <bits/stdc++.h>
using namespace std;

void func(int l, int r, vector<int> a, int &mx)
{
    mx = a[l];
    for (int i = l; i <= r; i++)
    {
        mx = max(a[i], mx);
    }
}

vector<int> slidingMaximum(const vector<int> &A, int b)
{
    int mx = INT_MIN;
    for (int i = 0; i < A.size() && i < b; i++)
    {
        mx = max(A[i], mx);
    }
    vector<int> res = {mx};
    int l = 0;
    for (int i = b; i < A.size(); i++)
    {
        if (mx < A[i])
        {
            mx = A[i];
            l++;
            res.emplace_back(mx);
            continue;
        }
        if (A[l] == mx)
        {
            func(l + 1, i, A, mx);
        }
        l++;
        res.emplace_back(mx);
    }
    return res;
}

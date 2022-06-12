// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void func(int num, vector<int> &candidates, vector<int> &tempRes, int index)
    {
        if (num < 0)
            return;
        if (num == 0)
        {
            res.push_back(tempRes);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            tempRes.push_back(candidates[i]);
            func(num - candidates[i], candidates, tempRes, i);
            tempRes.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> t;
        func(target, candidates, t, 0);
        return res;
    }
};
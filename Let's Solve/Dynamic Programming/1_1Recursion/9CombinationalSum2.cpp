// https://leetcode.com/problems/combination-sum-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;

    void myRecursion(int num, vector<int> &candidates, vector<int> &resTemp, int index)
    {
        if (num < 0)
            return;
        if (num == 0)
        {
            res.push_back(resTemp);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {

            if (index < i)
            {
                if (candidates[i] == candidates[i - 1])
                    continue;
            }

            resTemp.push_back(candidates[i]);
            myRecursion(num - candidates[i], candidates, resTemp, i + 1);
            resTemp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> resTemp;
        myRecursion(target, candidates, resTemp, 0);
        return res;
    }
};
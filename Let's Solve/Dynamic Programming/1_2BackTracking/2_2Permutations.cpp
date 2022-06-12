// No extra variable data structure used.

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>> res;

    void recurse(vector<int> &nums, int c)
    {

        if (c == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = c; i < nums.size(); i++)
        {
            swap(nums[i], nums[c]);
            recurse(nums, c + 1);
            swap(nums[i], nums[c]);
        }

        return;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        recurse(nums, 0);

        return res;
    }
};
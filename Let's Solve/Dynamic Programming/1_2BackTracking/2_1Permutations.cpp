// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>

using namespace std;

// TimeComplexity: n!*n
// SpaceComplexity: O(N)+O(N)
class Solution
{
public:
    vector<vector<int>> res;

    void recurse(vector<int> &nums, vector<int> &vis, vector<int> &sequence)
    {

        if (sequence.size() == nums.size())
        {
            res.push_back(sequence);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i])
                continue;
            vis[i] = 1;
            sequence.push_back(nums[i]);
            recurse(nums, vis, sequence);
            vis[i] = 0;
            sequence.pop_back();
        }

        return;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> vis(nums.size(), 0);
        vector<int> sequence;
        recurse(nums, vis, sequence);
        return res;
    }
};
// Generating subsets using bitmasking
// https://leetcode.com/problems/subsets/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Note time complexity:
    // Using bitmasking:    O(N*(2^N))
    // Using recursion:     O(2^N)
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        int subset_count = (1 << n);
        for (int i = 0; i < subset_count; i++)
        {
            vector<int> vec;
            for (int j = 0; j < n; j++)
            {
                if ((i & (1 << j)))
                {
                    vec.push_back(nums[j]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
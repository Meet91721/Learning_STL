// https://leetcode.com/problems/xor-queries-of-a-subarray/
#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> prefix;
        prefix.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            prefix.push_back(arr[i] ^ prefix[i - 1]);
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] == 0)
            {
                res.push_back(prefix[queries[i][1]]);
            }
            else
            {
                res.push_back(prefix[queries[i][1]] ^ prefix[queries[i][0] - 1]);
            }
        }
        return res;
    }
};
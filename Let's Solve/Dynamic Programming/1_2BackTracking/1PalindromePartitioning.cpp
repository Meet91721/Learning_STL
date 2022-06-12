// https://leetcode.com/problems/palindrome-partitioning/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int hi = s.length() - 1;
        int lo = 0;
        while (hi > lo)
        {
            if (s[hi] != s[lo])
                return false;
            hi--;
            lo++;
        }
        return true;
    }

    vector<vector<string>> res;

    void func(string s, vector<string> &temp)
    {
        if (s.size() == 0)
        {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (isPalindrome(s.substr(0, i + 1)))
            {
                temp.push_back(s.substr(0, i + 1));
                func(s.substr(i + 1, s.length() - 1 - i), temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        func(s, temp);
        return res;
    }
};
// https://leetcode.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    /*  This gave TLE
    constexpr static int N = 1001;
    string memo[N][N];

    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    string recurse(string& s, int l, int r){
        if(isPalindrome(s,l,r))
            return s.substr(l,r-l+1);
        if(memo[l][r] != "")
            return memo[l][r];
        string s1 = recurse(s,l,r-1);
        string s2 = recurse(s,l+1,r);
        if(s1.length()>s2.length()){
            memo[l][r] = s1;
            return s1;
        }
        memo[l][r] = s2;
        return s2;
    }
    */

    vector<int> funcc(string &s, int l, int r)
    {
        while (s[l] == s[r])
        {
            if (l == 0 || r == s.length() - 1)
                return {l, r};
            l--;
            r++;
        }
        if (s[l] == s[r])
            return {l, r};
        return {l + 1, r - 1};
    }

    string longestPalindrome(string s)
    {
        int mx = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++)
        {
            auto a = funcc(s, i, i);
            if (a[1] - a[0] + 1 > mx)
            {
                mx = a[1] - a[0] + 1;
                l = a[0];
                r = a[1];
            }
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            auto a = funcc(s, i, i + 1);
            if (a[1] - a[0] + 1 > mx)
            {
                mx = a[1] - a[0] + 1;
                l = a[0];
                r = a[1];
            }
        }
        return s.substr(l, r - l + 1);
    }
};
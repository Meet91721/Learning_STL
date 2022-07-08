// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool func(vector<int> &v1, vector<int> &v2)
    {
        for (int i = 0; i < 26; i++)
            if (v1[i] != v2[i])
            {
                return false;
            }
        return true;
    }

    int search(string txt, string pat)
    {
        // code here

        if (pat.size() < txt.size())
            return 0;
        vector<int> v(26, 0);
        vector<int> temp(26, 0);

        for (int i = 0; i < txt.size(); i++)
        {
            v[txt[i] - 'a']++;
            temp[pat[i] - 'a']++;
        }
        int res = func(v, temp);
        int l = 0;
        for (int i = txt.size(); i < pat.size(); i++)
        {
            temp[pat[i] - 'a']++;
            temp[pat[l] - 'a']--;
            res += func(v, temp);
            l++;
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
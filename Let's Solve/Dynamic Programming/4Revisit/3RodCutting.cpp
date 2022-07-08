// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[1005];

    int funcc(int length, vector<int> &price)
    {
        // if(ind < 0){
        //     return INT_MIN;
        // }
        if (length == 0)
            return 0;

        if (dp[length] != -1)
            return dp[length];

        int res = 0;
        for (int i = 1; i <= price.size(); i++)
        {
            if (length - i >= 0)
            {
                res = max(res, funcc(length - i, price) + price[i - 1]);
            }
        }

        return dp[length] = res;
    }

    int cutRod(int price[], int n)
    {
        // code here
        vector<int> prices(price, price + n);
        memset(dp, -1, sizeof(dp));
        return funcc(n, prices);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends
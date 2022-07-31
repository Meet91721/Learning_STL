// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Matrix Chain Multiplication

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int dp[101][101];

    int recurse(int i, int j, int arr[])
    {
        if (i == j)
        {
            return 0;
        }
        if (dp[i][j] != 0)
            return dp[i][j];
        int t = INT_MAX;
        for (int k = i; k < j; k++)
        {
            t = min(t, arr[i - 1] * arr[k] * arr[j] + recurse(i, k, arr) + recurse(k + 1, j, arr));
        }
        return dp[i][j] = t;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                dp[i][j] = 0;
        return recurse(1, N - 1, arr);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
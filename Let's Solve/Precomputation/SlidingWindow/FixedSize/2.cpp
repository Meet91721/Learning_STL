// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int n, long long int k)
{
    queue<long long int> q;
    for (long long int i = 0; i < k; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }
    }
    long long int l = 0, r = k - 1;
    l++;
    r++;
    vector<long long int> v;
    while (r <= n)
    {

        if (q.empty())
            v.push_back(0);
        else
            v.push_back(q.front());
        if (A[r] < 0)
            q.push(A[r]);
        if (A[l - 1] < 0)
        {
            q.pop();
        }
        r++;
        l++;
    }
    return v;
}
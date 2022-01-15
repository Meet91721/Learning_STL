/*
Given an array a of N integers. Given Q queries
and in each query given a number X, print
count of that number in array

Constrainsts:
1 <= N <= 10^5
1 <= a[i] <= 10^7
1 <= Q <= 10^5
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 10;

int main()
{
    /*
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == x)
                    count++;
            }
            cout << count << endl;
        }
        // Time Complexty: O(N)+O(Q*N)~O(N^2)=10^10
    */
    int n;
    cin >> n;
    map<long long, long> mp;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int temp;
        cin >> temp;
        cout << temp << "->" << mp[temp] << endl;
    }
}
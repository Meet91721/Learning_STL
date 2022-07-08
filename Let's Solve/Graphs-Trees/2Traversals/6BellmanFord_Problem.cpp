// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

// Dijkstra fails when negative weights are present
// BellmanFord fails when there is negative weight cycle

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here
        vector<int> distance(n, INT_MAX);
        if (n == 1 || edges.size() == 0)
            return 0;
        distance[edges[0][0]] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                if (distance[edges[j][0]] == INT_MAX)
                    continue;
                distance[edges[j][1]] = min(distance[edges[j][1]], edges[j][2] + distance[edges[j][0]]);
            }
        }
        vector<int> duplicate = distance;
        for (int j = 0; j < edges.size(); j++)
        {
            if (distance[edges[j][0]] == INT_MAX)
                continue;
            duplicate[edges[j][1]] = min(duplicate[edges[j][1]], edges[j][2] + duplicate[edges[j][0]]);
        }
        for (int i = 0; i < n; i++)
        {
            if (duplicate[i] != distance[i])
                return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
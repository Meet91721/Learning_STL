// https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<pair<int, int>> g[n + 1];
        for (int i = 0; i < times.size(); i++)
        {
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // Distance, Destination
        set<pair<int, int>> priorityQ;

        vector<bool> vis(n + 1, false);
        vector<int> distance(n + 1, INT_MAX);

        priorityQ.insert({0, k});

        while (priorityQ.size() > 0)
        {

            auto [wt, dst] = *priorityQ.begin();
            priorityQ.erase(priorityQ.begin());
            distance[dst] = min(wt, distance[dst]);

            if (vis[dst])
                continue;
            vis[dst] = true;

            for (int i = 0; i < g[dst].size(); i++)
            {
                priorityQ.insert({g[dst][i].second + wt, g[dst][i].first});
            }
        }

        int res = *max_element(++distance.begin(), distance.end());
        if (res == INT_MAX)
            return -1;
        return res;
    }
};

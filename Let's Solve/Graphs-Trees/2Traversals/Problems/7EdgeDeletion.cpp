#include <bits/stdc++.h>

using namespace std;
int precompute(vector<int> &A, map<int, vector<int>> &B, int node)
{
    if (node >= A.size())
    {
        return 0;
    }

    auto it = B.find(node);

    int temp = A[node];
    if (it != B.end())
    {
        for (auto &i : it->second)
        {
            temp += precompute(A, B, i);
        }
        A[node] = temp;
    }

    return temp;
}

int deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    map<int, vector<int>> graph;
    for (int i = 0; i < B.size(); i++)
    {
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }

    precompute(A, graph, 1);
    // int mid = A[0] / 2;
    // int closest = 0;
    // for(int i = 0; i < A.size(); i++){
    //     if(abs(i - mid) < abs(closest - mid)){
    //         closest = i;
    //     }
    // }
    // return closest * (A[0] - closest);
    return A[0];
}

/*
Given Q queries, Q <= 10^5
In each query given V,
Print subtree sum of given V
and number of even numbers in
subtree of V
*/

// There is some flaw in this code
// Sum working odd, even not working
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];

int odd[N];
int even[N];
int sum[N];

vector<int> precompute(int vertex, int par = 0)
{

    if (sum[vertex])
    {
        return {sum[vertex], even[vertex], odd[vertex]};
    }
    if (g[vertex].size() == 0)
    {

        sum[vertex] = vertex;
        odd[vertex] = (vertex % 2 == 0);
        even[vertex] = 1 - even[vertex];
        return {sum[vertex], even[vertex], odd[vertex]};
    }
    int current_sum = vertex;
    int odd_count = vertex % 2 == 1;
    int even_count = vertex % 2 == 0;
    if ((g[vertex].size() == 1 && g[vertex][0] == par))
    {
        sum[vertex] = current_sum;
        even[vertex] = odd_count;
        odd[vertex] = even_count;
        return {sum[vertex], even[vertex], odd[vertex]};
    }

    vector<vector<int>> temp_vec;
    for (int i = 0; i < g[vertex].size(); i++)
    {
        if (g[vertex][i] != par)
        {
            temp_vec.push_back(precompute(g[vertex][i], vertex));
        }
    }

    for (int i = 0; i < temp_vec.size(); i++)
    {
        current_sum += temp_vec[i][0];
        odd_count += temp_vec[i][2];
        even_count += temp_vec[i][1];
    }

    sum[vertex] = current_sum;
    odd[vertex] = odd_count;
    even[vertex] = even_count;
    cout << vertex << " " << odd[vertex] << "->" << g[8][1] << "\t" << even[vertex] << '\n';

    return {sum[vertex], even[vertex], odd[vertex]};
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    precompute(1);
    for (int i = 1; i <= n; i++)
    {
        cout << sum[i] << "\t" << odd[i] << "\t" << even[i] << '\n';
    }

    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int v;
    //     cin >> v;
    // }
}

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
4 11
*/
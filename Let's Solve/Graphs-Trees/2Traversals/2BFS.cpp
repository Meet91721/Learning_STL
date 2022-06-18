#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];

int queue1[N];
int head = -1;
int tail = -1;
void push(int n)
{
    if (head == -1)
    {
        head = 0;
        tail = 0;
        queue1[0] = n;
    }
    else
    {
        tail++;
        queue1[tail] = n;
    }
}
int pop()
{
    int temp;
    if (head == tail)
    {
        temp = queue1[head];
        head = -1;
        tail = -1;
    }
    else
    {
        temp = queue1[head];
        head++;
    }
    return temp;
}

bool visited[N] = {false};

void BFS(int node)
{
    push(node);
    cout << node << " ";
    visited[node] = 1;
    while (head != -1)
    {
        int t = pop();
        int size = g[t].size();
        for (int i = 0; i < size; i++)
        {
            if (visited[g[t][i]] != 1)
            {
                visited[g[t][i]] = 1;
                push(g[t][i]);
                cout << g[t][i] << " ";
            }
        }
    }
    // TIME COMPLEXITY:  O(V + E)
    return;
}

int main()
{
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;
    cout << "Enter the connected components: \n";
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (auto j : g[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << '\n';
    // }
    cout << "Enter the node to start BFS from: ";
    int node;
    cin >> node;
    BFS(node);
}
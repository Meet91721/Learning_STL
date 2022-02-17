// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/segment-tree/sum-of-interval-official/ojquestion
#include <bits/stdc++.h>

using namespace std;
void buildTree(int tree[], int arr[], int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        int left = node * 2;
        int right = node * 2 + 1;
        buildTree(tree, arr, left, start, mid);
        buildTree(tree, arr, right, mid + 1, end);
        tree[node] = tree[right] + tree[left];
    }
}

int solveQuery(int tree[], int arr[], int node, int start, int end, int l, int r)
{
    if (end < l || start > r)
    {
        return 0;
    }
    if (start >= l && end <= r)
    {
        return tree[node];
    }
    if (start == end)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left = solveQuery(tree, arr, node * 2, start, mid, l, r);
    int right = solveQuery(tree, arr, node * 2 + 1, mid + 1, end, l, r);
    return left + right;
}

void updateQuery(int tree[], int arr[], int node, int start, int end, int pos, int val)
{
    if (start == end)
    {
        tree[node] = val;
        arr[pos] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
        {
            updateQuery(tree, arr, node * 2, start, mid, pos, val);
        }
        else
        {
            updateQuery(tree, arr, node * 2 + 1, mid + 1, end, pos, val);
        }
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int tree[4 * n];
    buildTree(tree, arr, 1, 0, n - 1);
    // for (int i = 1; i < n * 4; i++)
    //     cout << tree[i] << " ";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            cout << solveQuery(tree, arr, 1, 0, n - 1, b, c) << endl;
        else
        {
            updateQuery(tree, arr, 1, 0, n - 1, b, c);
        }
    }
}
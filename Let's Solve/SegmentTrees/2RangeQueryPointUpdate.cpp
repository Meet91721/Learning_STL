// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/segment-tree/max-in-a-interval-range-query-point-update-official/ojquestion

#include <bits/stdc++.h>

using namespace std;

void buildTree(int tree[], int arr[], int l, int r, int node)
{
    if (l == r)
    {
        tree[node] = arr[r];
        return;
    }
    int mid = (l + r) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    buildTree(tree, arr, l, mid, left);
    buildTree(tree, arr, mid + 1, r, right);
    tree[node] = max(tree[left], tree[right]);
}

int solveQuery(int tree[], int node, int start, int end, int l, int r)
{
    if (end < l || start > r)
        return INT_MIN;
    if (start >= l && end <= r)
        return tree[node];
    if (start == end)
        return tree[node];
    int mid = (start + end) / 2;
    int left = solveQuery(tree, node * 2, start, mid, l, r);
    int right = solveQuery(tree, node * 2 + 1, mid + 1, end, l, r);
    return max(left, right);
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
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tree[n * 4];
    buildTree(tree, arr, 0, n - 1, 1);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            int small = solveQuery(tree, 1, 0, n - 1, b, c);
            cout << small << endl;
        }
        else
        {
            updateQuery(tree, arr, 1, 0, n - 1, b, c);
        }
    }
}
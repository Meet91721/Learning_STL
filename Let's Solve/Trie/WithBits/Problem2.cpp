// https://www.codingninjas.com/codestudio/problems/maximum-xor_973113?

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *bits[2];
    bool containsKey(int n)
    {
        return bits[n] != NULL;
    }
    void set(int n)
    {
        bits[n] = new Node();
    }
    Node *get(int n)
    {
        return bits[n];
    }
};

Node *r1;
Node *r2;

void insert(int n, int root)
{
    Node *node = r1;

    if (root == 2)
        node = r2;
    for (int i = 31; i >= 0; i--)
    {
        int bit = ((n >> i) & 1);
        if (!node->containsKey(bit))
        {
            node->set(bit);
        }
        node = node->get(bit);
    }
}

int recurse(Node *n1, Node *n2, int i)
{
    if (i < 0)
        return 0;
    int res = 0;
    bool b = false;
    if ((n1->containsKey(0) && n2->containsKey(1)))
    {
        b = true;
        res |= (1 << i);
        res |= recurse(n1->get(0), n2->get(1), i - 1);
    }
    if (n1->containsKey(1) && n2->containsKey(0))
    {
        int temp = (1 << i);
        b = true;
        res = max(res, temp | recurse(n1->get(1), n2->get(0), i - 1));
    }
    if (b)
        return res;
    if (n1->containsKey(0))
    {
        return recurse(n1->get(0), n2->get(0), i - 1);
    }
    return recurse(n1->get(1), n2->get(1), i - 1);
}

int funcc()
{
    int res = 0;
    Node *n1 = r1;
    Node *n2 = r2;
    return recurse(n1, n2, 31);
}

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here.
    r1 = new Node();
    r2 = new Node();
    for (int i = 0; i < n; i++)
    {
        insert(arr1[i], 1);
    }
    for (int i = 0; i < m; i++)
    {
        insert(arr2[i], 2);
    }
    return funcc();
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v1(n), v2(m);
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int i = 0; i < m; i++)
            cin >> v2[i];
        cout << maxXOR(n, m, v1, v2);
    }
}
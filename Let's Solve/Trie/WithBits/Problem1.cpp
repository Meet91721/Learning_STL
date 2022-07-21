// Given an array of numbers and a number x.Find the maximum value of arr[i] ^ x

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *bits[2];
    bool containsKey(int n)
    {
        return bits[n] != NULL;
    }
    void set(int n, Node *node)
    {
        bits[n] = node;
    }
    Node *get(int n)
    {
        return bits[n];
    }
};

Node *root;

void insert(int n)
{
    Node *node = root;
    for (int i = 31; i >= 0; i--)
    {
        int bit = ((n >> i) & (1));
        if (!node->containsKey(bit))
        {
            node->set(bit, new Node());
        }
        node = node->get(bit);
    }
}

int funcc(vector<int> &v, int n)
{
    root = new Node();
    for (int i = 0; i < v.size(); i++)
    {
        insert(v[i]);
    }
    Node *node = root;
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = ((n >> i) & (1));
        if (!node->containsKey(1 - bit))
        {
            node = node->get(bit);
        }
        else
        {
            res |= (1 << i);
            node = node->get(1 - bit);
        }
    }
    return res;
}

int main()
{
    vector<int> v = {9, 8, 7, 5, 4};
    int n = 7;
    cout << funcc(v, n);
}
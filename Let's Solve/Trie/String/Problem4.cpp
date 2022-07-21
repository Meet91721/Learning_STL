// https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *link[26];
    bool containsKey(char ch)
    {
        return link[ch - 'a'];
    }
    Node *get(char ch)
    {
        return link[ch - 'a'];
    }
    void set(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
};

Node *root;

void insert(string word)
{
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            node->set(word[i], new Node());
        }
        node = node->get(word[i]);
    }
}

int funcc(Node *node)
{

    int res = 0;
    for (int i = 0; i < 26; i++)
    {
        if (node->link[i])
        {
            res += 1 + funcc(node->link[i]);
        }
    }
    return res;
}

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    root = new Node();
    for (int i = 0; i < s.size(); i++)
        insert(s.substr(i));
    return 1 + funcc(root);
}
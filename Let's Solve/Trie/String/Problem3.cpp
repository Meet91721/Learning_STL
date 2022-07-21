// https://www.codingninjas.com/codestudio/problems/complete-string_2687860?

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void set(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

Node *root;

void insert(string &word)
{
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (!node->containsKey(word[i]))
            node->set(word[i], new Node());
        node = node->get(word[i]);
    }
    node->flag = true;
}

string res;

void funcc(Node *node, string &st)
{
    if (node->flag)
    {
        if (res.size() < st.size())
            res = st;
        // return;
    }
    else
        return;
    for (int i = 0; i < 26; i++)
    {
        if (node->containsKey(i + 'a'))
        {
            st += (i + 'a');
            funcc(node->get(i + 'a'), st);
            st.pop_back();
        }
    }
}

string completeString(int n, vector<string> &a)
{
    root = new Node();
    for (int i = 0; i < n; i++)
        insert(a[i]);
    string temp;
    Node *node = root;
    for (int i = 0; i < 26; i++)
    {
        if (node->containsKey(i + 'a'))
        {
            temp += (i + 'a');
            funcc(node->get(i + 'a'), temp);
            temp.pop_back();
        }
    }
    string ans = res;
    res = "";
    if (ans == "")
        return "None";
    return ans;
}

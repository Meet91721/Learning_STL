// https://codeforces.com/contest/455/problem/B

// SHREE
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define PI 3.141592653589793238462

struct Node
{
    Node *list[26];
    bool win = false;
    bool lose = false;
    bool containsKey(char ch)
    {
        return list[ch - 'a'];
    }
    void set(char ch)
    {
        list[ch - 'a'] = new Node();
    }
    Node *get(char ch)
    {
        return list[ch - 'a'];
    }
};

Node *root;

void insert(string &word)
{
    Node *node = root;
    for (int i = 0; i < word.size(); i++)
    {
        if (!node->containsKey(word[i]))
        {
            node->set(word[i]);
        }
        node = node->get(word[i]);
    }
}

bool isOdd = false, isEven = false;

bool ftw(Node *node = root)
{
    bool found = false;
    for (int i = 0; i < 26; i++)
    {
        if (node->containsKey(i + 'a'))
        {
            found = true;
            if (!ftw(node->get(i + 'a')))
            {
                node->win = true;
                return true;
            }
        }
    }
    node->win = false;
    return false;
}

bool ftl(Node *node = root)
{
    bool found = false;
    for (int i = 0; i < 26; i++)
    {
        if (node->containsKey(i + 'a'))
        {
            found = true;
            if (!ftl(node->get(i + 'a')))
            {
                node->lose = true;
                return true;
            }
        }
    }
    if (found)
    {
        node->lose = false;
        return false;
    }
    node->lose = true;
    return true;
}

void solve()
{
    root = new Node();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        insert(t);
    }
    ftl();
    ftw();
    if (root->win == false)
    {
        cout << "Second";
        return;
    }
    if (root->win && root->lose)
    {
        cout << "First";
        return;
    }
    if (root->win == true)
    {
        if (m & 1)
        {
            cout << "First";
        }
        else
            cout << "Second";
        return;
    }
}

int32_t main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *links[26];
    int tillHere = 0;
    int stopsHere = 0;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void set(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->set(word[i], new Node());
            }
            node->tillHere++;
            node = node->get(word[i]);
        }
        node->tillHere++;
        node->stopsHere++;
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->stopsHere;
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->tillHere;
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            node->tillHere--;
            node = node->get(word[i]);
        }
        node->tillHere--;
        node->stopsHere--;
    }
};

// Write a function `canConstruct(target, wordBank)` that takes in a
// targetString and an array of strings as an arguments

// The function should return boolean depending whether or not the `target`
// can be constructed using the concatenation of words from `wordBank`.

// Elements of `wordBank` can be reused

#include <bits/stdc++.h>
using namespace std;

void eraseAllSubStr(string &mainstr, string toerase)
{
    size_t pos = std::string::npos;
    while ((pos = mainstr.find(toerase)) != std::string::npos)
    {
        mainstr.erase(pos, toerase.length());
    }
}

bool canConstruct(string target, string wordBank[], int size)
{
    if (target == "")
    {
        return true;
    }
    bool t1 = false;
    for (int i = 0; i < size; i++)
    {
        string temp = target;
        eraseAllSubStr(temp, wordBank[i]);
        if (temp == target)
            continue;
        t1 = (t1 | canConstruct(temp, wordBank, size));
        if (t1)
            return t1;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string tgt;
        cin >> tgt;
        int q;
        cin >> q;
        string s[q];
        for (int i = 0; i < q; i++)
        {
            cin >> s[i];
        }
        cout << (canConstruct(tgt, s, q) ? "It is possible\n" : "It is not possible\n");
    }
}
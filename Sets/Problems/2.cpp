#include <bits/stdc++.h>

using namespace std;
/*
Given N strings and Q queries.
Print yes if that element is present
else print no.
*/

// INPUT
/*
8
abc
def
abc
ghj
jkl
ghj
ghj
abc
3
abc
ghj
meet
*/
int main()
{
    int n;
    cin >> n;
    unordered_set<string> s;
    while (n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string temp;
        cin >> temp;
        auto it = s.find(temp);
        if (it != s.end())
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
#include <bits/stdc++.h>

using namespace std;
/*
Given n string print unique strings in
lexicographical order
*/

// Input
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
*/
int main()
{
    int n;
    cin >> n;
    set<string> s;
    while (n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }
    cout << "\nUsing string:\n";
    for (auto &val : s)
    {
        cout << val << endl;
    }
    cout << "\nUsing iterator:\n";
    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
}
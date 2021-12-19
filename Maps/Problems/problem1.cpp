#include <bits/stdc++.h>

/*Given n string print unique strings
in lexicographical order with their frequency*/
// INPUTS:
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
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> m;
    while (n--)
    {
        string temp;
        cin >> temp;
        m[temp] += 1;
    }
    for (auto &val : m)
    {
        cout << val.first << ": " << val.second << endl;
    }
}
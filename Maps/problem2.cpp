#include <bits/stdc++.h>

using namespace std;

/*Gived N strings and Q queries.
In each query you are given a string
print frequency of that string*/
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
2
abc
ghj
*/
int main()
{
    unordered_map<string, int> m;

    // Using unordered_map since there is
    // no requirements of sorting the array
    // Also unordered_map has far better complexity than the previous one
    int t;
    cin >> t;
    while (t--)
    {
        string temp;
        cin >> temp;
        m[temp]++;
    }
    int queries;
    cin >> queries;
    while (queries--)
    {
        string temp;
        cin >> temp;
        cout << m[temp] << endl;
    }
}
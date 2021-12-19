#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {1, 8, 6, 3, 53, 2, 7};
    // Range based loops
    cout << "Printing using range based loops: \n";
    for (int &value : v)
    {
        cout << value << "\t";
    }
    cout << endl;
    // auto keyword
    cout << "Printing using auto keyword:\n";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;

    // For vector of pair
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {4, 5}, {9, 8}};
    cout << "\nPrinting vectors of pairs using range based loops:\n";
    for (pair<int, int> &p : vp)
    {
        cout << p.first << "\t" << p.second << endl;
    }
    cout << "Printing vectors of pairs using auto keyword and range based loops:\n";
    for (auto &val : vp)
    {
        cout << val.first << "\t" << val.second << endl;
    }
}
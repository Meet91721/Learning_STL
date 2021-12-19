#include <bits/stdc++.h>

using namespace std;

void PRINT(unordered_set<string> &s)
{
    cout << "Size of set: " << s.size() << endl;
    if (s.size())
    {
        for (auto &val : s)
        {
            cout << val << "\t";
        }
        cout << endl;
    }
}
int main()
{
    unordered_set<string> s;
    // Implemented using hash table
    // Hence, output might seem random

    // Unoredered_set has same constraints as
    // unordered_map has

    // insertion, find all have time complexity of O(1)
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    PRINT(s);
}
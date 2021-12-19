#include <bits/stdc++.h>

using namespace std;

void PRINT(set<string> &s)
{
    cout << "Size of set: " << s.size() << endl;
    if (s.size())
    {
        for (auto &val : s) // val is pointer to string
        {
            cout << val << "\t";
        }
        cout << endl;
        /*
                // using iterator
                for (auto it = s.begin(); it != s.end(); it++) // using iterator
                {
                    cout << *it << "\t";
                }
                cout << endl;
        */
    }
}
int main()
{
    // Not Really- map without values is set

    // 3 types
    //  i) set
    //  ii) unordered_set
    //  iii) multiset

    set<string> s;    // Stores only unique elements in sorted order
    s.insert("abc");  // O(logn)
    s.insert("zsdf"); // implemented using RedBlackTree
    s.insert("bcd");

    // Accessing and insertion: O(logn)
    // find() returns iterator
    // returns s.end() if element not found
    auto it = s.find("abc"); // O(logn)
    if (it != s.end())
    {
        cout << (*it) << endl;
    }
    else
    {
        cout << "No such element found\n";
    }
    cout << endl;
    PRINT(s);

    // s.erase()
    // erase can take either iterator or the element as its input
    if (it != s.end())
        s.erase(it);

    cout << "\nElements after deleting the 'it':\n";
    PRINT(s);
}
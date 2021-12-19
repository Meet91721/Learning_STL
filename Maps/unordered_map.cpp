#include <bits/stdc++.h>

using namespace std;
void PRINT(unordered_map<int, string> m)
{
    cout << "Size: " << m.size() << endl;
    if (m.size() != 0)
    {
        cout << "Elements in the map:\n";
        for (auto &pr : m)
        {
            cout << pr.first << ": " << pr.second << endl;
        }
    }
}
int main()
{
    unordered_map<int, string> m;
    // Note that sets, vectors, and other variables are not
    // allowed in unordered_map since their hashing is not defined
    // However they can be used in map since their comparison is
    // possible

    //  Insertion is done using hash table
    //  Hence print looks random

    //  Insertion: O(1)
    //  Accessing: O(1)
    m[1] = "abc";
    m[5] = "cdc";
    m[3] = "acd";
    m[6];
    m[5] = "cde";
    m.insert({4, "afg"});
    PRINT(m);
    /*
    find, erase and all other syntaxes in map
    can be used in unordered_map as it is
    find: O(1)
    erase: O(1)
    */
}
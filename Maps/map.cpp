#include <bits/stdc++.h>

using namespace std;

void PRINT(map<int, string> &m)
{
    cout << "Size of map: " << m.size() << endl;
    if (m.size() != 0)
    {
        cout << "Map content\n";
        for (auto &it : m)
        {
            cout << it.first << ":  " << it.second << endl;
        } // O(nlog(n))
        // Accessing has a complexity of O(log(n))
    }
}
int main()
{
    // map
    map<int, string> m;
    // Though we have not inserted elements in sorted order it gets
    // stored in sorted order since map stores elements in sorted
    // order. Implemented using red black tree.
    m[1] = "abc"; // O(log(n))      NOTE: comparison complexity has to be multiplied explicitly
    m[5] = "cdc";
    m[3] = "acd";
    m[6];
    m[5] = "cde"; // Shows keys are unique
    m.insert({4, "afg"});
    PRINT(m);
    // find(returns iterator)
    // return m.end() in case of key not present in the map
    // NOTE: here 6 will not return m.end()
    auto it = m.find(3); // O(log(n))
    if (it != m.end())
        cout << "Found 3: " << it->second << endl;

    // Now let's erase values
    // 2 inputs are possible: (i)key (ii)iterator
    //(i) key
    m.erase(3);
    m.erase(10); // Will not give any error
    cout << "\nAfter deleting using key:\n";
    PRINT(m);
    //(ii) iterator
    // will give error when iterator points to m.end()
    it = m.find(6);
    m.erase(it);
    it = m.find(3);
    // m.erase(it); This will give error
    cout << "\nAfter deleting using iterator:\n";
    PRINT(m);

    m.clear();
    cout << "\nAfter clearing the map:\n";
    PRINT(m);
}
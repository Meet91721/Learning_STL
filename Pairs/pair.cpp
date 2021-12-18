#include <bits/stdc++.h>

using namespace std;
int main()
{
    pair<int, string> p1, p2;                      // Declaration
    p1 = make_pair(2, "abc");                      // Method1: Assigning values
    p2 = {2, "xyz"};                               // Method2: Assigning values
    cout << p1.first << "\t" << p1.second << endl; // Printing values
    cout << p2.first << "\t" << p2.second << endl; // Printing values

    // Zindagi achhi chal rahi he?
    // Then let's add pointers.

    // Initialising by reference
    pair<int, string> &p3 = p1;
    p3.first = 7;
    cout << p1.first << "\t" << p1.second << endl; // Printing values
    cout << p3.first << "\t" << p3.second << endl; // Printing values

    // Array of pairs
    pair<int, int> p_array[3];
    for (int i = 0; i < 3; i++)
    {
        p_array[i] = {i + 1, i + 2};
    }

    // Printing array of pairs
    for (int i = 0; i < 3; i++)
        cout << p_array[i].first << "\t" << p_array[i].second << endl;

    // Let's swap
    swap(p_array[0], p_array[2]);
    for (int i = 0; i < 3; i++)
        cout << p_array[i].first << "\t" << p_array[i].second << endl;
}
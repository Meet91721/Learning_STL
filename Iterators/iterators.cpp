#include <bits/stdc++.h>

using namespace std;
int main()
{

    // iterators for vectors
    vector<int> v = {1, 3, 52, 5, 8, 4, 7};
    vector<int>::iterator it = v.begin();

    // Only use it++ or ++it to traverse to the next element
    // it + 1 might work for vectors but it won't work for maps
    // and other non contiguous containers since it is not necessary
    // that next element is stored on the next memory address.
    cout << "Elements in vectors: \n";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << endl;
    }

    // iterators for vector of pairs
    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {7, 8}};
    vector<pair<int, int>>::iterator it1;
    cout << "Elements in vectors of pairs(m1): \n";
    for (it1 = v_p.begin(); it1 != v_p.end(); it1++)
    {
        cout << (*it1).first << "\t" << (*it1).second << endl;
    }

    // You know the next method of printing ;)
    cout << "Elements in vectors of pairs(m2): \n";
    for (it1 = v_p.begin(); it1 != v_p.end(); ++it1)
    {
        cout << it1->first << "\t" << it1->second << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    cout << "Size of vector: " << v.size() << endl; // O(1)
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
}

void print_with_reference(vector<int> &v) // Here reference is passed, has much better complexity than copying vectors
{
    cout << "Size of vector: " << v.size() << endl; // O(1)
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int main()
{
    // Vectors has dynamic size
    //  Declaring and initializing
    vector<int> v;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1); // O(1)
    }
    print(v);

    // Can also declare a vector with size all elements will be 0
    vector<int> v1(10);
    print(v1);
    // Note this
    v1.push_back(7);
    print(v1);

    // Can also declare a vector with size and all elements
    vector<int> v2(10, 3);
    print(v2);

    // Deleting last value
    v2.pop_back(); // O(1)
    print(v2);

    // Copying vectors
    vector<int> v_copy = v1; // O(n)
}
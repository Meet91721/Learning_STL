#include <bits/stdc++.h>
using namespace std;
// Array vectors

void PRINT(vector<int> &v)
{
    cout << "Size: " << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
}
int main()
{
    vector<int> v[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            v[i].push_back(j + 1);
        }
    }
    for (int i = 0; i < 3; i++)
        PRINT(v[i]);
}
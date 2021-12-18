#include <bits/stdc++.h>
using namespace std;

// Vector of vectors
void PRINT(vector<int> v)
{
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl
         << endl;
}
int main()
{
    vector<vector<int>> v;
    cout << "Enter rows: ";
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        v.push_back(vector<int>());
        cout << "Enter number of columns: ";
        int c;
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    for (int i = 0; i < N; i++)
        PRINT(v[i]);
}
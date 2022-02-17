#include <bits/stdc++.h>

using namespace std;

bool should_i_swap(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}

int main()
{
    vector<int> vec = {1, 6, 12, 5, 32, 7, 5, 2, 14, 3, 63, 2};
    cout << "This is just to prove that comparator function works in reverse order:\n";
    sort(vec.begin(), vec.end());
    for (auto &val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
    sort(vec.begin(), vec.end(), should_i_swap);
    for (auto &val : vec)
    {
        cout << val << " ";
    }
}
#include <bits/stdc++.h>

using namespace std;
int arr[10];

// Reverse the array
void REVERSE(int point)
{
    // cout << "HI";
    int size = sizeof(arr) / sizeof(arr[1]);
    if (point <= size / 2)
    {
        swap(arr[point], arr[size - point - 1]);
        REVERSE(point + 1);
    }
    return;
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    REVERSE(0);
    for (auto &val : arr)
        cout << val << "\t";
}
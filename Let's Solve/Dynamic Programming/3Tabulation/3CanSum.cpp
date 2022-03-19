// Write a function `canSum(targetSum, numbers)` that takes in a
// targetSum and an arrayof numbers as an arguments

// The function should return a boolean indicating whether or not it
// is possible to generate the targetSum using numbers from the array.

// You may use an element of the array as many times as needed
// You may assume that all inputs are nonnegative

#include <bits/stdc++.h>
using namespace std;
const int N = 100;
bool res[N + 1];

void canSum(int sum, int arr[], int len)
{
    res[0] = true;

    for (int i = 0; i < N; i++)
    {
        if (res[i])
        {
            for (int j = 0; j < len; j++)
            {
                if (i + arr[j] < N)
                    res[i + arr[j]] = true;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the target sum: ";
    cin >> n;
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    canSum(n, arr, len);
    if (res[n])
    {
        cout << "Yes it is possible!!!";
    }
    else
    {
        cout << "Naseeb j nathi :')";
    }

    // Time Complexity: O(n * len)
    // Space Complexity: O(N)
}
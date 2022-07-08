/*
    Given array a of n integers. All integers are present in even count, except one.
    Find that one integer which has odd count in O(N) time complexity and O(1) space.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[9] = {2, 2, 1, 4, 4, 1, 2, 5, 5};
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        num = (num ^ arr[i]);
    }
    cout << num;
}
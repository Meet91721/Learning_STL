// https://www.geeksforgeeks.org/xor-sum-every-possible-pair-array/

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int sumXOR = 0;
    for (int i = 0; i < N; i++)
    {
        sumXOR = sumXOR ^ (2 * arr[i]);
    }
    cout << sumXOR << endl;
}
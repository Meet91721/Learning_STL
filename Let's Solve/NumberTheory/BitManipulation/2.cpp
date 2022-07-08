// Given a number N and an index i, find whether ith bit is set or not

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, i;
    cin >> N >> i;
    int check = 1;
    check = check << (i - 1);
    if (N & check)
        cout << "It is set";
    else
        cout << "Not set";
}
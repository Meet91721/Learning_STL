#include <bits/stdc++.h>

using namespace std;
int SUMMATION(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + SUMMATION(n - 1);
}
int main()
{
    int sum = SUMMATION(5);
    printf("%d", sum);
}
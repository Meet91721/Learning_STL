#include <bits/stdc++.h>

using namespace std;
// Print factorial of n

int FACT(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * FACT(n - 1);
}

int main()
{
    int fact = FACT(5);
    printf("%d", fact);
}
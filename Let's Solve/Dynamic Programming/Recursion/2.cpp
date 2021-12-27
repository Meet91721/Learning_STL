#include <bits/stdc++.h>

using namespace std;

// Print from 1 to N
void PRINT(int n)
{
    if (n == 0)
    {
        return;
    }
    PRINT(n - 1);
    printf("%d\n", n);
}
int main()
{
    PRINT(5);
}
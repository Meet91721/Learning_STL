#include <bits/stdc++.h>

using namespace std;
// Print from n to 1
void PRINT(int n)
{
    if (n == 0)
    {
        return;
    }
    printf("%d\n", n);
    PRINT(n - 1);
}

main()
{
    PRINT(5);
}
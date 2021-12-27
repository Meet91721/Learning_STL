#include <bits/stdc++.h>

using namespace std;
// Print  name 5 times
void PRINT(int n)
{
    if (n != 0)
    {
        printf("Meet Amin\n");
        PRINT(--n);
    }
    else
        return;
}
int main()
{
    PRINT(5);
}
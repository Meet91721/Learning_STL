#include <bits/stdc++.h>

using namespace std;
int main()
{
    int a = 12;
    int b = 22;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    // step2: b = (a^b)^b = a^(b^b) = a^(0) = a
    // step3: a = (a^b)^a = (a^a)^b = (0)^b = b
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
}
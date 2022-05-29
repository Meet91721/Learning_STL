#include <bits/stdc++.h>

using namespace std;

void print_binary(int n)
{
    for (int i = 15; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << '\n';
}

void lower_to_upper(char c)
{
    char b = c & '_';
    cout << b << '\n';
}

void upper_to_lower(char c)
{
    cout << (char(c | ' ')) << '\n';
}

void clear_LSBs(int num, int n)
{
    // Clear n LSBs from num in just one operation
    int res = (num & (~((1 << (n + 1)) - 1)));
    print_binary(res);
}

void clear_MSBs(int num, int n)
{
    // Clears n MSBs from num in just one operation
    int res = (num & ((1 << n) - 1));
    print_binary(res);
}

void is_power_of_2(int n)
{
    int res = n & (n - 1);
    if (res)
    {
        cout << n << " is not a power of 2\n";
    }
    else
    {
        cout << n << " is a power of 2\n";
    }
}

int main()
{
    lower_to_upper('c');
    upper_to_lower('C');

    int num = 123;
    int n = 3;
    cout << "Original Number: ";
    print_binary(num);
    cout << "After clearing " << n << " LSBs: ";
    clear_LSBs(num, n);
    cout << "After clearing upto " << n << " LSBs: ";
    clear_MSBs(num, n);
    is_power_of_2(num);
}
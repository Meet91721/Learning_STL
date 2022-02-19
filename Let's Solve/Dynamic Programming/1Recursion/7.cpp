#include <bits/stdc++.h>

using namespace std;

// Check if the string is palindrome

bool CHECK(int point, string s)
{
    int size = s.length();
    if (point <= size / 2)
    {
        if (s[point] == s[size - point - 1])
        {
            return CHECK(point + 1, s);
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    printf("The word is palindrome: %s", CHECK(0, "ACBA") ? "true" : "false");
}
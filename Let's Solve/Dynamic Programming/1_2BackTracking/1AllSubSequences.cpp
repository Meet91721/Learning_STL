// https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/

#include <bits/stdc++.h>

using namespace std;

void printSubsequence(string s, vector<char> &v, int i = 0)
{
    if (i == s.length())
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << '\n';
        return;
    }

    printSubsequence(s, v, i + 1);
    v.push_back(s[i]);
    printSubsequence(s, v, i + 1);
    v.pop_back();
}

int main()
{
    vector<char> v;
    string s = "abc";
    printSubsequence(s, v);
}
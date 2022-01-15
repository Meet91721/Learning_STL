// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/palindrome-queries-eefd5c23/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
        long q;
        cin >> q;
        string s;
        cin >> s;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            int hsh[26] = {0};
            l--;
            r--;
            for (int i = l; i <= r; i++)
            {
                hsh[s[i] - 'a']++;
            }
            int n = 0;
            for (int i = 0; i < 26; i++)
            {
                if (hsh[i] % 2 != 0)
                {
                    n++;
                }
            }
            if (n > 1)
            {
                cout << "Impossible\n";
            }
            else
            {
                cout << "Possible\n";
            }
        }
        //O(q*(s.length()))
    */
    long q;
    cin >> q;
    // string *s = (string *) malloc (sizeof(char) * (int) pow(10, 100));
    string s;
    scanf("%s", s);
    long long hsh[26][s.length() + 1] = {0};
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < s.length() + 1; j++)
        {
            hsh[i][j] = 0;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        hsh[s[i] - 'a'][i + 1]++;
    }

    // finding prefix sum of hsh array
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j <= s.length(); j++)
        {
            hsh[i][j] += hsh[i][j - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        long long int l, r;
        cin >> l >> r;
        int count = 0;
        for (int j = 0; j < 26; j++)
        {
            long temp = hsh[j][r] - hsh[j][l - 1];
            if (temp % 2 != 0)
            {
                count++;
            }
        }
        if (count > 1)
        {
            cout << "Impossible\n";
        }
        else
        {
            cout << "Possible\n";
        }
    }
}
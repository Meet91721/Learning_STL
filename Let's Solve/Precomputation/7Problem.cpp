// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/palindrome-queries-eefd5c23/
#include <bits/stdc++.h>

using namespace std;

int arr[26][100001];
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
    int q;
    cin >> q;
    string s;
    cin >> s;
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        // cout << i << " ";
        arr[s[i] - 'a'][1 + i]++;
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        int oddcnt = 0;
        for (int j = 0; j < 26; j++)
        {
            if ((arr[j][r] - arr[j][l - 1]) % 2 != 0)
                oddcnt++;
        }
        if (oddcnt > 1)
            cout << "Impossible\n";
        else
            cout << "Possible\n";
    }
}
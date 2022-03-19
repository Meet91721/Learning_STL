// Write a function `canConstruct(target, wordBank)` that takes in a
// targetString and an array of strings as an arguments

// The function should return boolean depending whether or not the `target`
// can be constructed using the concatenation of words from `wordBank`.

// Elements of `wordBank` can be reused

#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string target, string wordbank[], int len)
{
    int t_len = target.size();
    bool arr[t_len + 1] = {false};
    arr[0] = true;
    char c_arr[t_len];
    for (int i = 0; i < t_len; i++)
    {
        c_arr[i] = target[i];
    }
    for (int i = 0; i < t_len; i++)
    {
        if (arr[i] != true)
            continue;
        for (int j = 0; j < len; j++)
        {

            if (c_arr[i] == wordbank[j][0])
            {
                int temp = wordbank[j].size();
                if (c_arr[i + temp - 1] == wordbank[j][temp - 1])
                    arr[i + temp] = true;
            }
        }
    }

    // for (int i = 0; i < t_len + 1; i++)
    // {
    //     cout << arr[i] << '\t';
    // }

    return arr[t_len];
}

int main()
{
    string target;
    cout << "Enter the target string: ";
    cin >> target;
    int len;
    cout << "Enter the length of the wordbank: ";
    cin >> len;
    string wordbank[len];
    for (int i = 0; i < len; i++)
    {
        cin >> wordbank[i];
    }
    cout << canConstruct(target, wordbank, len);
}
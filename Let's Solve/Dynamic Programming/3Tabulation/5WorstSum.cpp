// Write a function `worstSum(targetSum, numbers)` that takes in a
// targetSum and an array of numbers as an arguments

// The function should return an array containing the longest
// combination of numbers that add upto exactly the targetSum.

// If there is any tie for the shortest combinations you can return
// any of the combination

#include <bits/stdc++.h>
using namespace std;
const int N = 10;
vector<pair<bool, vector<int>>> res(N + 1);

void worstSum(int n, int arr[], int len)
{
    res[0] = {true, {}};
    for (int i = 0; i < N + 1; i++)
    {
        if (res[i].first == true)
            for (int j = 0; j < len; j++)
            {
                if (i + arr[j] < N)
                {
                    res[arr[j] + i].second.clear();
                    for (int x = 0; x < res[i].second.size(); x++)
                    {
                        res[arr[j] + i].second.push_back(res[i].second[x]);
                    }

                    res[arr[j] + i].first = true;
                    res[i + arr[j]].second.push_back(arr[j]);
                }
            }
    }
}

int main()
{
    int n;
    cout << "Enter the target sum: ";
    cin >> n;
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    worstSum(n, arr, len);
    if (res[n].first)
    {
        cout << "Yes it is possible\n";
        for (int i = 0; i < res[n].second.size(); i++)
        {
            cout << res[n].second[i] << " ";
        }
    }
    else
    {
        cout << "Naseeb j nathi :')";
    }
}
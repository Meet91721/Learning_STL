// https://www.geeksforgeeks.org/sum-xor-pairs-array/

#include <bits/stdc++.h>

using namespace std;

// Accepted solution on GFG
class Solution
{
public:
    long long int sumXOR(int arr[], int n)
    {
        long long res = 0;
        // NOTE it is less than 31, since MSB is reserved for sign
        for (int i = 0; i < 31; i++)
        {
            long long int checker = 1 << (i);
            int set = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] & checker)
                    set++;
            }
            long long int multi = set * (n - set) * pow(2, i);
            res += multi;
        }
        return res;
    }
};

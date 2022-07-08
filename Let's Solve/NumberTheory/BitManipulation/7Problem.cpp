// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int n = (a | b), XOR = (n ^ c), count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (XOR & (1 << i))
            {
                if ((a & (1 << i)) && (b & (1 << i)))
                {
                    count += 2;
                }
                else
                    count++;
            }
        }
        return count;
    }
};
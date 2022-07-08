/*
    4 fruits are numbered as follows:
        0. Apple
        1. Banana
        2. Cherry
        3. Lichi
    2 persons have some of these fruits
    Find common fruits between them.
    person1: 1,3
    person2: 0,2,3
*/

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int p1[2] = {1, 3};
    int p2[3] = {0, 2, 3};
    int p1_liking = 0;
    int p2_liking = 0;
    for (int i = 0; i < 2; i++)
    {
        p1_liking += (1 << p1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        p2_liking += (1 << p2[i]);
    }
    int commonLiking = (p1_liking & p2_liking);
    // cout << p1_liking << " " << p2_liking << '\n';
    // cout << commonLiking;
    vector<int> likes;
    for (int i = 0; i < 5; i++)
    {
        if ((commonLiking & (1 << i)))
        {
            likes.push_back(i);
        }
    }

    for (auto &fruits : likes)
    {
        cout << fruits << " ";
    }
    // We have limits of 32 bits(in case of int) and 64bits (in case of long long) :/
}
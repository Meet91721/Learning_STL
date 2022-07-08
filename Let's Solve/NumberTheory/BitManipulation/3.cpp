// Given a number N find the number of set bits in it.

#include <bits/stdc++.h>

using namespace std;
int main()
{
    // Approach-1 (logarithmic complexity)
    /*
        int N, count = 0, checker = 1;
        cin >> N;
        while (N)
        {
            if (N & checker)
            {
                count++;
            }
            N = N >> 1;
        }
        cout << "Number of set bits = " << count;
    */
    // Approach-2 (while loop runs only till the time there are set bits in the number)
    int N, count = 0;
    cin >> N;
    while (N)
    {
        count++;
        N = N & (N - 1);
    }
    cout << count;
}
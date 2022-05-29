// Binary search can be applied on any monotonic function
// On predicate function as well (TTTFFF)
// Time complexity: O(log2(N))
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    vector<int> v(n);
    v = {2, 3, 4, 5, 6, 7};
    int to_find = 5;
    int lo = 0, hi = n - 1;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (v[mid] < to_find)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[hi] == to_find)
    {
        cout << hi << '\n';
    }
    else if (v[lo] == to_find)
    {
        cout << lo << '\n';
    }
    else
        cout << "NOTfound\n";
}
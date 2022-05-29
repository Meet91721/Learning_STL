// Some built in algorithms
#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v(10);
    v = {2, 3, 1, 4, 12, 4, 6, 8, 45, 6};
    // All the below function works the same for arrays as well
    // Just change v.begin() -> v
    // v.end() -> v + n
    int min = *min_element(v.begin(), v.end());
    int max = *max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    int ct = count(v.begin(), v.end(), 3);
    int index = *find(v.begin(), v.end(), 3);
    cout << "Minimum element: " << min << "Maximum Element: " << max << "\n";
    cout << "Sum of vector: " << sum << '\n';
    cout << "Count of 3 in vector is: " << ct << '\n';
    cout << "3 can be found at: " << index << '\n';
    reverse(v.begin(), v.end()); // Works the same way for string as well
    string s = "asdakjbkfs";
    reverse(s.begin(), s.end());
}
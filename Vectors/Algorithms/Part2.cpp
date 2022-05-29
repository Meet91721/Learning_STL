#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Lambda function :
    cout << [](int a)
    { return a + 2; }(3)
         << '\n';

    vector<int> v(3);
    v = {-1, 0, 2};
    cout << all_of(v.begin(), v.end(), [](int a)
                   { return a >= 0; })
         << '\n';
    cout << any_of(v.begin(), v.end(), [](int a)
                   { return a >= 0; })
         << '\n';
    cout << none_of(v.begin(), v.end(), [](int a)
                    { return a >= 0; })
         << '\n';
}
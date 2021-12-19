#include <bits/stdc++.h>

using namespace std;

void PRINT(multiset<string> &s)
{
    cout << "Size: " << s.size() << endl;
    if (s.size())
        for (auto &val : s)
            cout << val << "\t";
    cout << endl;
}
int main()
{
    multiset<string> s;
    // RedBlackTree is used
    // All functions have complexity same
    // as of set
    // Hence sorting too is done as usual

    // But this allows duplicate elements

    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    PRINT(s);

    // find() if found multiple values
    // returns pointer to the first element
    auto it = s.find("abc");
    if (it != s.end())
    {
        s.erase(it);
        cout << "\nElements after erasing iterator: \n";
        PRINT(s);
    }

    // about erase()
    // if passed iterator it will delete only that
    //  particular element
    //  If you pass element all other duplicates
    //  of that element will also get deleted
    s.erase("zsdf");

    cout << "\nElements after erasing using value: \n";
    PRINT(s);
}
#include <bits/stdc++.h>

using namespace std;

// O(N)
void method1(int n)
{
    vector<int> primes;
    // Note that this count is just for counting the number of steps this algo takes
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        count++;
        while (n % i == 0 && n != 0)
        {
            count++;
            primes.push_back(i);
            n /= i;
        }
    }
    for (auto &element : primes)
    {
        cout << element << '\t';
    }
    cout << "\nHere count: " << count << '\n';
}

// O(sqrt(N))
void method2(int n)
{
    // Note that this count is just for counting the number of steps this algo takes
    int count = 0;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++)
    {
        count++;
        while (n % i == 0 && n != 0)
        {
            count++;
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        primes.push_back(n);
    }

    for (auto &element : primes)
    {
        cout << element << '\t';
    }
    cout << "\nHere count: " << count << '\n';
}

int main()
{
    int n = 36;
    // Observe the difference in count :)
    method1(3600002);
    method2(3600002);
    method1(3600001);
    method2(3600001);
}
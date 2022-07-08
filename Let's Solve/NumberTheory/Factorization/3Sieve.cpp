#include <bits/stdc++.h>
using namespace std;

// Sieve algorithm: precomputing of prime numbers
const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);

// (❁´◡`❁)            O(N*log(log(N)))              ╰(*°▽°*)╯
void sieve(int n)
{
    isPrime[0] = isPrime[1] = 0;
    // i*i would be better than this
    // But jesa chal raha he chal ne do
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << isPrime[i] << '\n';
    }
}

int main()
{
    int n = 30;
    sieve(n);
}
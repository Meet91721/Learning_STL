// Calculating highest and lowest prime factor of a number
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int H[N];
int L[N];
vector<bool> isPrime(N, 1);

auto factorz(int n)
{
    map<int, int> res;
    while (n > 1)
    {
        int prime_factor = H[n];
        int count = 0;
        while (n % prime_factor == 0 && n != 0)
        {
            count++;
            n /= prime_factor;
        }
        res[prime_factor] = count;
    }
    return res;
}

void sieve(int n)
{
    isPrime[0] = isPrime[1] = 0;
    H[1] = L[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            L[i] = i;
            H[i] = i;
            for (int j = 2 * i; j <= N; j += i)
            {
                isPrime[j] = false;
                H[j] = i;
                if (L[j] == 0)
                {
                    L[j] = i;
                }
            }
        }
    }
    cout << "\tHighest\tLowest\tFactors(with count)\n";
    for (int i = 2; i < n; i++)
    {
        map<int, int> factors = factorz(i);

        cout << i << "\t" << H[i] << "\t" << L[i] << '\t';
        for (auto &element : factors)
        {
            cout << element.first << "->" << element.second << ",\t";
        }
        cout << '\n';
    }
}

int main()
{
    int n = 30;
    sieve(n);
}
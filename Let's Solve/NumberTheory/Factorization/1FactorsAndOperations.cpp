// Note that this has time complexity of O(sqrt(N))
// But for answering q queries this might be pretty slow
// For that find all the prime factors: p1^n1, p2^n2, p3^n3, ...., pk^nk(say)
// Count = (n1+1)(n2+1)(n3+1)...(nk+1)
// Sum  = (1+p1+p1^2+p1^3+...+p1^n1)(1+p2+p2^2+p2^3+...+p2^n2)(1+p3+p3^2+p3^3+...+p3^n3)...(1+pk+pk^2+pk^3+...+pk^nk)
//      = (p1^n1-1)/(p1-1)(p2^n2-1)/(p2-1)(p3^n3-1)/(p3-1)...(pk^nk-1)/(pk-1)

#include <bits/stdc++.h>

using namespace std;

// Time Complexity: sqrt(N)
void func(int n)
{
    int sum = 0;
    int cnt = 0;
    vector<int> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            cnt++;
            factors.push_back(i);
            if (i != n / i)
            {
                sum += n / i;
                cnt++;
                factors.push_back(n / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    cout << "Factors are:\t";
    for (int i = 0; i < factors.size(); i++)
        cout << factors[i] << " \n"[i == factors.size() - 1];
    cout << "Sum of factors is: " << sum << '\n';
    cout << "Number of factors: " << cnt << '\n';
}

int main()
{
    func(24);
    func(36);
}
// So proud of how I use lambda with accumulate function

// https://www.spoj.com/problems/EKO/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n, m;
    cin >> n >> m;
    vector<unsigned long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unsigned long long int hi = *max_element(arr.begin(), arr.end()), lo = 0;

    while (hi - lo > 1)
    {
        unsigned long long int mid = (hi + lo) / 2;
        unsigned long long int sum = accumulate(arr.begin(), arr.end(), 0LL, [&mid](unsigned long long int a, unsigned long long int b)
                                                {
        	if(b > mid){
        		return (unsigned long long)(a + b - mid);
        	}
        	return (unsigned long long)(a); });
        if (sum >= m)
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    unsigned long long s = accumulate(arr.begin(), arr.end(), 0LL, [&hi](unsigned long long int a, unsigned long long int b)
                                      {
    	if(b > hi){
    		return (unsigned long long)(a + b - hi);
    	}
    	return (unsigned long long)a; });
    if (s >= m)
    {
        cout << hi << '\n';
    }
    else
    {
        cout << lo << '\n';
    }
}
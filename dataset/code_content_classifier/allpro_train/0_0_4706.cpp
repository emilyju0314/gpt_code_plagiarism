#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long power(long long x, long long y)
{
    long long res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1; 
        x = (x * x) % MOD;
    }
    return res;
}

int main()
{
    int n;
    long long m, k;
    cin >> n >> m >> k;
    
    long long ans = 1;
    if (k == 0)
    {
        ans = power(n, m);
    }
    else if (k == 1)
    {
        ans = power(n, (m+1)/2);
    }
    else if (k == n*n)
    {
        ans = power(n, (m+1)/2);
    }
    else if (n % 2 == 1)
    {
        ans = n;
    }
    else
    {
        ans = 2;
    }
    
    cout << ans << endl;
    
    return 0;
}
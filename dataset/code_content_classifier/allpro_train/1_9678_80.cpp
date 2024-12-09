#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
    long long n, c[200005], d[200005], x;
    cin >> n;
    long long a[n], b[n];
    for (long long i = 0; i < 200005; i++) 
    {
        c[i] = 0;
        d[i] = 0;
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
        d[b[i]]++;
    }
    for (long long i = 0; i < 200005; i++)
    {
        if (c[i] + d[i] > n)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++)
    {
	    c[i] += c[i - 1];
	    d[i] += d[i - 1];
    }
    for (int i = 1; i <= n; i++) x = max(x, c[i] - d[i - 1]);
    for (int i = 0; i < n; i++)
    	cout << b[(i + n - x) % n] << ' ';
}

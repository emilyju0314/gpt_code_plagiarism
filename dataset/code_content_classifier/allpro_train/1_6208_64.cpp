#include <iostream>
#include <algorithm>
using namespace std;

long long n, m = 0;
long long c[200000], y[200001];
const long long M = 1000000007;

int main()
{
    cin >> n;

    y[0] = 1;
    y[1] = 2;
    for (int i = 1; i < n; i++)
        y[i + 1] = y[i] * 2 % M;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(c, c + n);

    if (n > 1) {
        for (int i = 0; i < n; i++)
            m = (m + (((n - i + 1) * y[n - 2] % M) * y[n] % M) * c[i]) % M;
    }
    else
        m = 2 * c[0] % M;
 
    cout << m << endl;

    return 0;
}

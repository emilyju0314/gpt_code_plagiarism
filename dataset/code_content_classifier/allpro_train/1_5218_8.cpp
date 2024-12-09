#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t, n, m, k, maxi, c, d, x, p, s;
    vector <long long> prime(2e7 + 1, 0);
    for (int i = 2; i <= 2e7; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= 2e7; j += i) {
            prime[j]++;
        }
    }
    //for (int i = 0; i < 25; ++i) {
    //    cout << prime[i] << " ";
    //}
    cin >> t;
    while (t--) {
        cin >> c >> d >> x;
        s = 0;
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                n = x / i + d;
                if (n % c == 0) {
                    k = n / c;
                    p = 1;
                    p = (1 << prime[k]);
                    /*)
                    for (int j = 2; j * j <= k; ++j) {
                        if (k % j == 0) {
                            p *= 2;
                        }
                        while (k % j == 0) {
                            k /= j;
                        }
                    }

                    if (k != 1) {
                        p *= 2;
                    }*/
                    s += p;
                }

            }
            if (x % i == 0 && i * i != x) {
                n = i + d;
                if (n % c == 0) {
                    k = n / c;
                    p = 1;
                    p = (1 << prime[k]);
                    /*)
                    for (int j = 2; j * j <= k; ++j) {
                        if (k % j == 0) {
                            p *= 2;
                        }
                        while (k % j == 0) {
                            k /= j;
                        }
                    }

                    if (k != 1) {
                        p *= 2;
                    }*/
                    s += p;
                }

            }
        }
        cout << s << endl;
    }
}

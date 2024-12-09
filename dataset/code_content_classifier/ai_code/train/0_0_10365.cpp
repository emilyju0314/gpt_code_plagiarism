#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e6 + 5;

int n, k;
int np[maxn];
int b[maxn];

void sieve() {
    for(int i = 2; i <= k; i++) {
        if(np[i] == 0) {
            for(int j = i; j <= k; j += i) {
                np[j]++;
            }
        }
    }
}

int power(int a, int b) {
    int res = 1;
    while(b) {
        if(b % 2) {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    sieve();

    for(int i = 1; i <= k; i++) {
        b[i] = power(i, n);
    }

    for(int i = 2; i <= k; i++) {
        b[i] = (b[i] - b[i - 1] + mod) % mod;
    }

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        ans ^= b[i];
    }

    cout << ans << "\n";

    return 0;
}
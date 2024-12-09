#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007
#define MAX 72

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int x = a[i];
        vector<int> factors(MAX, 0);
        for(int j = 2; j * j <= x; j++) {
            while(x % j == 0) {
                x /= j;
                factors[j]++;
            }
        }
        if(x > 1) {
            factors[x]++;
        }
        int mask = 0;
        for(int j = 2; j < MAX; j++) {
            mask |= (factors[j] % 2) << (j - 2);
        }
        cnt[mask]++;
    }

    long long ans = (pow(2, cnt[0], MOD) - 1 + MOD) % MOD;
    for(auto it = cnt.begin(); it != cnt.end(); it++) {
        if(it->first == 0) continue;
        int inv_mask = (1 << 70) - 1 - it->first;
        for(int i = inv_mask; ; i = (i - 1) & inv_mask) {
            ans = (ans + pow(2, it->second, MOD) * pow(2, cnt[i], MOD)) % MOD;
            if(i == 0) break;
        }
    }

    cout << ans << endl;

    return 0;
}

long long pow(long long a, long long b, long long MOD) {
    long long res = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}
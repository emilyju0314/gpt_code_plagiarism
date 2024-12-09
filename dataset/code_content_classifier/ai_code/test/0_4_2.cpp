#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(k == 1) {
        cout << (long long)n * (n + 1) / 2 % MOD * m % MOD << endl;
    } else {
        unordered_map<int, int> count;
        int sum = 0;
        count[0] = 1;
        long long ans = 0;

        for(int i = 0; i < n * m; i++) {
            sum = (sum + a[i % n]) % k;
            ans = (ans + count[(k - sum) % k]) % MOD;
            count[sum]++;
        }

        cout << ans << endl;
    }

    return 0;
}
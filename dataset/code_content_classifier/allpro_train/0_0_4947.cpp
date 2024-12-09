#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    long long ans = 0;
    // Brute force all possible answer suits
    for (int i = 1; i <= k; i++) {
        vector<int> a(n);
        a[0] = i;
        for (int j = 1; j < n; j++) {
            a[j] = ((i + j) % k) + 1;
        }
        // Check if this answer suit satisfies the condition
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == h[j]) {
                cnt++;
            }
        }
        if (cnt > 0) {
            ans = (ans + 1) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
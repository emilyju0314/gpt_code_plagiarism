#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int fact(int n) {
    if (n <= 1) return 1;
    return (n * fact(n-1)) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sa(n);
    for (int i = 0; i < n; i++) {
        cin >> sa[i];
    }

    int ans = 1;
    int prev_diff = 0;
    for (int i = 1; i < n; i++) {
        int diff = 0;
        for (int j = 0; j < n; j++) {
            if (sa[j] < i) diff++;
        }
        
        if (diff > prev_diff) {
            ans = (ans * (k - (diff - prev_diff))) % MOD;
        } else {
            ans = (ans * diff) % MOD;
        }

        prev_diff = diff;
    }

    cout << ans << endl;

    return 0;
}
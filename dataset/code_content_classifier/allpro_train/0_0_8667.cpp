#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            long long beauty = a[j] - a[i];
            int count = 0;

            for(int p = 0; p < n; p++) {
                if(a[p] == a[i] || a[p] == a[j]) {
                    count++;
                }
            }

            if(count >= k) {
                ans = (ans + beauty) % MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
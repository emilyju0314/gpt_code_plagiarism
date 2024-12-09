#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            long long cur = 0;
            for (int j = i; j < n; j++) {
                cur = min(cur + a[j], (long long)a[j]); 
                sum += cur;
                total_sum = (total_sum + sum) % MOD;
            }
        }

        cout << total_sum << endl;
    }

    return 0;
}
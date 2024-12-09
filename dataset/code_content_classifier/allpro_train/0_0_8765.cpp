#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(k);
        vector<int> pos(n+1, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = 0; i < k; i++) {
            cin >> b[i];
        }

        long long ans = 1;
        for (int i = 0; i < k; i++) {
            int cnt = 0;

            if (pos[b[i] - 1] != -1 && pos[b[i] - 1] + 1 < pos[b[i]]) {
                cnt++;
                pos[b[i] - 1] = -1;
            }

            if (pos[b[i] + 1] != -1 && pos[b[i] + 1] + 1 < pos[b[i]]) {
                cnt++;
                pos[b[i] + 1] = -1;
            }

            ans = (ans * cnt) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}
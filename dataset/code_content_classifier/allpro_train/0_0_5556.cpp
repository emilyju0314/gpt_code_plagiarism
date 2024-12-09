#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int checkpoints = 1;
    long long total_days = 0;
    long long prob_not_beautiful = 500; // 100/2

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        u--;

        if (p[u] == 100) {
            total_days = (total_days + prob_not_beautiful) % MOD;
            prob_not_beautiful = (prob_not_beautiful * 2) % MOD;
        } else {
            total_days = (total_days + prob_not_beautiful) % MOD;
            prob_not_beautiful = (prob_not_beautiful * 2) % MOD;
            for (int j = u + 1; j < n; j++) {
                if (p[j] == 100) {
                    checkpoints++;
                    break;
                }
            }
        }

        cout << total_days << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int ans = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        unordered_set<string> subsequence_set;
        string subsequence = "";

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subsequence += strings[i];
            }
        }

        int k = subsequence.size();
        for (int i = 0; i < pow(2, k); i++) {
            string temp = "";
            for (int j = 0; j < k; j++) {
                if ((i >> j) & 1) {
                    temp += subsequence[j];
                }
            }

            if (!temp.empty()) {
                subsequence_set.insert(temp);
            }
        }

        int f = subsequence_set.size();
        ans ^= (1LL * f * k) % MOD;
    }

    cout << ans << endl;

    return 0;
}
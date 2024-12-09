#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int total_xor = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        unordered_set<string> unique_subs;
        vector<int> sub_lengths;
        int total_len = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                unique_subs.insert("");
                int len = strings[i].size();
                total_len += len;
                for (int j = 1; j < len; j++) {
                    string sub = strings[i].substr(0, j);
                    unique_subs.insert(sub);
                }
                sub_lengths.push_back(len);
            }
        }

        for (auto subs : unique_subs) {
            for (int len : sub_lengths) {
                if (len >= subs.size()) {
                    total_xor = (total_xor + subs.size() * len) % MOD;
                }
            }
        }
    }

    cout << total_xor << endl;

    return 0;
}
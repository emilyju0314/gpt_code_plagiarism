#include <iostream>
#include <vector>
#include <algorithm>
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

    vector<int> coeffs(n);
    for (int i = 0; i < n; i++) {
        coeffs[i] = i + 1;
    }

    int total = 0;
    int mask = (1 << n) - 1;

    for (int subset = 0; subset < (1 << n); subset++) {
        int cnt = 0;
        unordered_set<string> substrings;

        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) {
                cnt += coeffs[i];
                for (char c : strings[i]) {
                    string substr;
                    for (int j = i; j >= 0; j--) {
                        if (subset & (1 << j)) {
                            substr += c;
                        }
                    }
                    substrings.insert(substr);
                }
            }
        }

        long long f = substrings.size();
        f %= MOD;
        total ^= (f * cnt) % MOD;
    }

    cout << total << endl;

    return 0;
}
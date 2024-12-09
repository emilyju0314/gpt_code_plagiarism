#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    vector<int> values(n, 0);
    for(int i = 0; i < n; i++) {
        for(char c : strings[i]) {
            values[i] = (values[i] * 26 + (c - 'a')) % MOD;
        }
    }

    int ans = 0;
    int total = 0;
    int k = pow(2, n);
    for(int i = 1; i < k; i++) {
        vector<int> subsequence_values;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                subsequence_values.push_back(values[j]);
            }
        }

        unordered_set<int> subsequences;
        for(int j = 1; j < pow(2, subsequence_values.size()); j++) {
            int subsequence_val = 0;
            int count = 0;
            for(int l = 0; l < subsequence_values.size(); l++) {
                if(j & (1 << l)) {
                    subsequence_val += subsequence_values[l];
                    count++;
                }
            }
            subsequences.insert(subsequence_val);
            total = (total + count) % MOD;
        }

        int xor_sum = 0;
        for(int val : subsequences) {
            xor_sum ^= val;
        }
        ans = (ans + xor_sum) % MOD;
    }

    ans = (ans * total) % MOD;

    cout << ans << endl;

    return 0;
}
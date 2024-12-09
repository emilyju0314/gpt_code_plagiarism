#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    unordered_set<string> substrings;

    for (int i = 0; i < (1 << n); i++) {
        string subseq = "";
        int num_strings = 0;
        int idx_sum = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subseq += strings[j];
                num_strings++;
                idx_sum += j + 1;
            }
        }

        substrings.insert(subseq);
    }

    long long result = 0;

    for (auto sub : substrings) {
        result += sub.size() * num_strings * idx_sum;
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}
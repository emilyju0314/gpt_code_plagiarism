#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longest_common_prefix(string x, string y) {
    int lcp = 0;
    for (int i = 0; i < min(x.size(), y.size()); i++) {
        if (x[i] == y[i]) {
            lcp++;
        } else {
            break;
        }
    }
    return lcp;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> proteins(n);
    for (int i = 0; i < n; i++) {
        cin >> proteins[i];
    }

    int max_representativity = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != k) continue;

        int representativity = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) {
                        representativity = max(representativity, longest_common_prefix(proteins[i], proteins[j]));
                    }
                }
            }
        }

        max_representativity = max(max_representativity, representativity);
    }

    cout << max_representativity << endl;

    return 0;
}
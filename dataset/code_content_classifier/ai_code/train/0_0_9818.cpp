#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonPrefix(string x, string y) {
    int i = 0;
    while (i < x.length() && i < y.length() && x[i] == y[i]) {
        i++;
    }
    return i;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> proteins(n);
    for (int i = 0; i < n; i++) {
        cin >> proteins[i];
    }

    int maxRepresentativity = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) == k) {
            vector<string> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset.push_back(proteins[j]);
                }
            }

            int representativity = 0;
            for (int j = 0; j < subset.size(); j++) {
                for (int l = j + 1; l < subset.size(); l++) {
                    representativity += longestCommonPrefix(subset[j], subset[l]);
                }
            }

            maxRepresentativity = max(maxRepresentativity, representativity);
        }
    }

    cout << maxRepresentativity << endl;

    return 0;
}
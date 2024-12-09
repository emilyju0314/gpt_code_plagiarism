#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(string x, string y) {
    int len = 0;
    while (len < x.length() && len < y.length() && x[len] == y[len]) {
        len++;
    }
    return len;
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
        if (__builtin_popcount(mask) != k) {
            continue;
        }

        int representativity = 0;
        vector<string> selected_proteins;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                selected_proteins.push_back(proteins[i]);
            }
        }

        for (int i = 0; i < selected_proteins.size(); i++) {
            for (int j = i + 1; j < selected_proteins.size(); j++) {
                    representativity = max(representativity, f(selected_proteins[i], selected_proteins[j]));
            }
        }

        max_representativity = max(max_representativity, representativity);
    }

    cout << max_representativity << endl;

    return 0;
}
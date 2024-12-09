#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> warriors(n);
    vector<int> horses(n);

    for (int i = 0; i < n; i++) {
        cin >> warriors[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> horses[i];
    }

    long long total_strength = 0;
    for (int i = 0; i < n; i++) {
        total_strength += warriors[i] * horses[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        total_strength -= warriors[a] * horses[a];
        total_strength -= warriors[b] * horses[b];

        swap(horses[a], horses[b]);

        total_strength += warriors[a] * horses[a];
        total_strength += warriors[b] * horses[b];

        vector<long long> tmp(n);

        for (int i = 0; i < n; i++) {
            long long best = 0;
            for (int j = 0; j < n; j++) {
                best = max(best, (long long)warriors[i] * horses[j]);
            }
            tmp[i] = best;
        }

        for (int i = 0; i < n; i++) {
            total_strength = max(total_strength, total_strength - warriors[i] * horses[i] + tmp[i]);
        }

        cout << total_strength << endl;
    }

    return 0;
}
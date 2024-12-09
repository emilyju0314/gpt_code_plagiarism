#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    unordered_map<int, pair<int, int>> sums;

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sums[lengths[i] + lengths[j]] = make_pair(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        if (sums.find(lengths[i]) != sums.end()) {
            pair<int, int> indices = sums[lengths[i]];
            if (indices.first != i && indices.second != i) {
                cout << indices.first + 1 << " " << indices.second + 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
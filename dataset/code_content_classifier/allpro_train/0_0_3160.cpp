#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> pearls(n);
    unordered_map<int, vector<int>> type_indices;

    for (int i = 0; i < n; i++) {
        cin >> pearls[i];
        type_indices[pearls[i]].push_back(i);
    }

    vector<pair<int, int>> segments;

    for (auto entry : type_indices) {
        vector<int> indices = entry.second;

        if (indices.size() < 2) {
            continue;
        }

        for (int i = 0; i < indices.size() - 1; i += 2) {
            segments.push_back({indices[i], indices[i + 1]});
        }
    }

    if (segments.empty()) {
        cout << -1 << endl;
    } else {
        cout << segments.size() << endl;
        for (auto segment : segments) {
            cout << segment.first + 1 << " " << segment.second + 1 << endl;
        }
    }

    return 0;
}
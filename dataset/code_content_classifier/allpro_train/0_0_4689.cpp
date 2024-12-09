#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector<int> count(200001, 0);
    unordered_set<int> badPoints;
    for (int i = 0; i < n; i++) {
        for (int j = segments[i].first; j <= segments[i].second; j++) {
            count[j]++;
            if (count[j] > k) {
                badPoints.insert(j);
            }
        }
    }

    vector<int> toRemove;
    for (int i = 0; i < n; i++) {
        bool remove = false;
        for (int j = segments[i].first; j <= segments[i].second; j++) {
            if (badPoints.find(j) != badPoints.end()) {
                remove = true;
                break;
            }
        }
        if (remove) {
            toRemove.push_back(i+1);
        }
    }

    cout << toRemove.size() << "\n";
    for (int idx : toRemove) {
        cout << idx << " ";
    }

    return 0;
}
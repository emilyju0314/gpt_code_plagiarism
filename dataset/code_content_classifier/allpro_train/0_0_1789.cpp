#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cafes(n);
    unordered_map<int, int> lastVisitedIndex;

    for (int i = 0; i < n; i++) {
        cin >> cafes[i];
        lastVisitedIndex[cafes[i]] = i;
    }

    int longestNotVisitedIndex = 0;
    int maxDistance = -1;

    for (auto it = lastVisitedIndex.begin(); it != lastVisitedIndex.end(); ++it) {
        if (it->second > maxDistance) {
            maxDistance = it->second;
            longestNotVisitedIndex = it->first;
        }
    }

    cout << longestNotVisitedIndex << endl;

    return 0;
}
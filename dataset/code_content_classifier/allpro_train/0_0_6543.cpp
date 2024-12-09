#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    unordered_map<int, int> uniqueCounts;

    int minModes = INT_MAX;

    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        uniqueCounts[ai]++;
    }

    for(auto itr = uniqueCounts.begin(); itr != uniqueCounts.end(); itr++) {
        int pages = (x + itr->first - 1) / itr->first;
        if(pages * itr->first >= x) {
            minModes = min(minModes, pages + itr->second);
        }
    }

    if(minModes == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minModes << endl;
    }

    return 0;
}
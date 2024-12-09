#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(i+1);
    }

    for (int i = 1; i < n; i++) {
        if (pairs[i].second > pairs[i-1].second) {
            cout << 2 << "\n";
            cout << pairs[i-1].first << " " << pairs[i-1].second << "\n";
            cout << pairs[i].first << " " << pairs[i].second << "\n";
            return 0;
        }
    }

    cout << 1 << "\n";
    cout << pairs[0].first << " " << pairs[0].second << "\n";

    return 0;
}
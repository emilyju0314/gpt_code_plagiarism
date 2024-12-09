#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool solve(int n, vector<int>& a) {
    unordered_map<int, vector<pair<int, int>>> pairs;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            pairs[a[i] + a[j]].push_back({a[i], a[j]});
        }
    }

    sort(a.begin(), a.end());
    int sum = a[2 * n - 1] + a[2 * n - 2];
    if (pairs[sum].empty()) {
        return false;
    }

    cout << "YES" << endl;
    cout << sum << endl;
    while (!a.empty()) {
        pair<int, int> currentPair = pairs[sum].back();
        pairs[sum].pop_back();
        cout << currentPair.first << " " << currentPair.second << endl;
        a.erase(find(a.begin(), a.end(), currentPair.first));
        a.erase(find(a.begin(), a.end(), currentPair.second));
        sum = max(currentPair.first, currentPair.second);
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        if (!solve(n, a)) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> sociability(n);
        for (int i = 0; i < n; i++) {
            cin >> sociability[i].first;
            sociability[i].second = i + 1;
        }

        sort(sociability.begin(), sociability.end());

        vector<pair<int, int>> ans;
        for (int i = 0; i < n - 1; i++) {
            if (sociability[i].first > 0) {
                ans.push_back({sociability[i].second, sociability[n - 1].second});
                sociability[n - 1].first--;
                if (sociability[n - 1].first == 0) n--;
            }
        }

        cout << ans.size() << endl;
        for (auto &pair : ans) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}
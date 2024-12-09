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

        vector<int> sociabilities(n);
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            cin >> sociabilities[i];
        }

        int max_talks = min(n-1, count(sociabilities.begin(), sociabilities.end(), 0));

        cout << max_talks << endl;

        if (max_talks == 0) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (sociabilities[i] == 0) {
                ans.push_back({i + 1, (i + 1) % n + 1});
            }
        }

        int zero_count = count(sociabilities.begin(), sociabilities.end(), 0);
        for (int i = 0; i < n; i++) {
            if (sociabilities[i] != 0 && zero_count >= 1) {
                ans.push_back({1, i + 1});
                zero_count--;
            }
        }

        for (int i = 0; i < max_talks; i++) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}
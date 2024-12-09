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
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_talks = 0;
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && a[i] != 0 && a[j] != 0) {
                    max_talks = max(max_talks, min(a[i], a[j]));
                    ans.push_back({i + 1, j + 1});
                }
            }
        }

        cout << max_talks * 2 << endl;
        for (int i = 0; i < ans.size(); i++) {
            if (a[ans[i].first - 1] > 0 && a[ans[i].second - 1] > 0) {
                cout << ans[i].first << " " << ans[i].second << endl;
                a[ans[i].first - 1]--;
                a[ans[i].second - 1]--;
            }
        }
    }

    return 0;
}
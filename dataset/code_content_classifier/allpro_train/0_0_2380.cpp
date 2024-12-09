#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> levels(n);
    for(int i = 0; i < n; i++) {
        cin >> levels[i].first >> levels[i].second;
    }

    sort(levels.begin(), levels.end());

    int t = (n+1)*2;
    vector<int> ans(n, 0);

    for(int i = 0; i <= n; i++) {
        int stars = 0;
        vector<bool> used(n, false);

        for(int j = 0; j < i; j++) {
            stars += levels[j].first;
            used[j] = true;
        }
        for(int j = i; j < n && stars < w; j++) {
            stars += levels[j].second;
            used[j] = true;
        }

        if(stars >= w) {
            t = min(t, i*1 + (n-i)*2);

            for(int j = 0; j < n; j++) {
                ans[j] = used[j] ? (levels[j].first < levels[j].second ? 1 : 2) : 0;
            }
        }
    }

    cout << t << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
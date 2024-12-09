#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h, g;
        cin >> h >> g;

        int n = (1 << h) - 1;
        vector<int> a(n + 1), cnt(n + 1), vis(n + 1);
        vector<int> res;
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int cur = n;
        for (int i = n; i > 1; i--) {
            if (a[i] > 0 && a[i] > a[i / 2]) {
                cnt[i] = 1;
                vis[i] = 1;
                res.push_back(i);
                sum -= a[i];
                cur--;
            }
        }

        while (cur > (1 << g) - 1) {
            for (int i = 1; i <= n; i++) {
                if (cnt[i] && vis[i] && !vis[2 * i]) {
                    vis[2 * i] = 1;
                    res.push_back(2 * i);
                    cnt[i] = 0;
                    cnt[2 * i] = 1;
                    sum -= a[2 * i];
                    cur--;
                }
                if (cnt[i] && vis[i] && !vis[2 * i + 1]) {
                    vis[2 * i + 1] = 1;
                    res.push_back(2 * i + 1);
                    cnt[i] = 0;
                    cnt[2 * i + 1] = 1;
                    sum -= a[2 * i + 1];
                    cur--;
                }
            }
        }

        cout << sum << endl;

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
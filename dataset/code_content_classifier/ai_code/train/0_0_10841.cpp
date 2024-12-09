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

        int ans = 1;
        for (int x = 1; x <= 26; x++) {
            for (int y = 1; y <= 26; y++) {
                int left = -1, right = -1;
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] == x || a[i] == y) {
                        cnt++;
                        if (a[i] == x && left == -1) {
                            left = i;
                        }
                        if (a[i] == x) {
                            right = i;
                        }
                    }
                }
                ans = max(ans, 2 * min(cnt - (right - left + 1), cnt / 2) + (right - left + 1));
            }
        }

        cout << ans << endl;
    }

    return 0;
}
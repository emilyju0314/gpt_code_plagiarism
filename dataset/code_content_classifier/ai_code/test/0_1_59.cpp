#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> convenient(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> convenient[i][j];
            }
        }

        bool possible = false;
        for (int d1 = 0; d1 < 4; d1++) {
            for (int d2 = d1 + 1; d2 < 5; d2++) {
                int cnt1 = 0, cnt2 = 0;
                for (int i = 0; i < n; i++) {
                    if (convenient[i][d1] == 1 && convenient[i][d2] == 0) {
                        cnt1++;
                    } else if (convenient[i][d1] == 0 && convenient[i][d2] == 1) {
                        cnt2++;
                    }
                }
                if (cnt1 + cnt2 == n && cnt1 <= n / 2 && cnt2 <= n / 2) {
                    possible = true;
                    break;
                }
            }
            if (possible) {
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> days(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> days[i][j];
            }
        }

        bool possible = false;
        for (int d1 = 0; d1 < 5; d1++) {
            for (int d2 = d1 + 1; d2 < 5; d2++) {
                int count_d1 = 0, count_d2 = 0;
                for (int i = 0; i < n; i++) {
                    if (days[i][d1] == 1) {
                        count_d1++;
                    } else if (days[i][d2] == 1) {
                        count_d2++;
                    }
                }
                if (count_d1 + count_d2 == n && count_d1 <= n/2 && count_d2 <= n/2) {
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
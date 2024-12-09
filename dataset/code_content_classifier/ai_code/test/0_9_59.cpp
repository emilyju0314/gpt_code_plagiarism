#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<vector<int>> canAttend(n, vector<int>(5));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> canAttend[j][k];
            }
        }

        bool possible = false;
        for (int j = 0; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                int count1 = 0, count2 = 0;
                for (int l = 0; l < n; ++l) {
                    if (canAttend[l][j] == 1 && canAttend[l][k] == 0) {
                        count1++;
                    } else if (canAttend[l][j] == 0 && canAttend[l][k] == 1) {
                        count2++;
                    }
                }
                if (count1 == count2 && count1 + count2 == n) {
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
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> canAttend(n, vector<int>(5));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> canAttend[i][j];
            }
        }

        bool possible = false;
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                int countGroup1 = 0;
                int countGroup2 = 0;

                for (int k = 0; k < n; k++) {
                    if (canAttend[k][i] && !canAttend[k][j]) {
                        countGroup1++;
                    } else if (!canAttend[k][i] && canAttend[k][j]) {
                        countGroup2++;
                    }
                }

                if (countGroup1 + countGroup2 == n && countGroup1 == countGroup2) {
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
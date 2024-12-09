#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<vector<int>> days(n, vector<int>(5));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> days[j][k];
            }
        }

        bool possible = false;
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                int count1 = 0, count2 = 0;
                for (int l = 0; l < n; l++) {
                    if (days[l][j] && !days[l][k]) {
                        count1++;
                    } else if (!days[l][j] && days[l][k]) {
                        count2++;
                    }
                }
                if (count1 + count2 == n && count1 % 2 == 0 && count2 % 2 == 0) {
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
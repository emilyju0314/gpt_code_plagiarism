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
        for (int day1 = 0; day1 < 5; day1++) {
            for (int day2 = day1 + 1; day2 < 5; day2++) {
                int count1 = 0, count2 = 0;
                for (int j = 0; j < n; j++) {
                    if (days[j][day1] == 1 && days[j][day2] == 0) {
                        count1++;
                    } else if (days[j][day1] == 0 && days[j][day2] == 1) {
                        count2++;
                    }
                }
                if (count1 == count2) {
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
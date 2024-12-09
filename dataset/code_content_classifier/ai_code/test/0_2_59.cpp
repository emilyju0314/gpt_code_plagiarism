#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<vector<int>> students(n, vector<int>(5));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> students[j][k];
            }
        }

        bool possible = false;
        for (int day1 = 0; day1 < 5; ++day1) {
            for (int day2 = day1 + 1; day2 < 5; ++day2) {
                int group1 = 0, group2 = 0;
                bool valid = true;

                for (int j = 0; j < n; ++j) {
                    if (students[j][day1] == 1 && students[j][day2] == 0) {
                        group1++;
                    } else if (students[j][day1] == 0 && students[j][day2] == 1) {
                        group2++;
                    } else if (students[j][day1] == 1 && students[j][day2] == 1) {
                        valid = false;
                        break;
                    }
                }

                if (valid && group1 == group2 && group1 + group2 == n) {
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
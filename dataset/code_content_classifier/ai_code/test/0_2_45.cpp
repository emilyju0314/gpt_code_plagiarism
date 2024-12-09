#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> days(n);
        for (int i = 0; i < n; i++) {
            cin >> days[i];
        }

        int height = 1;
        int consecutive_days = 0;
        for (int i = 0; i < n; i++) {
            if (days[i] == 1) {
                if (consecutive_days > 0) {
                    height += 5;
                } else {
                    height += 1;
                }
                consecutive_days = 0;
            } else {
                consecutive_days++;
                if (consecutive_days == 2) {
                    break; // flower died
                }
            }
        }

        if (consecutive_days == 2) {
            cout << "-1" << endl;
        } else {
            cout << height << endl;
        }
    }

    return 0;
}
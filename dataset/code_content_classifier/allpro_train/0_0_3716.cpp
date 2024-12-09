#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> reservationTable(n);
        for (int i = 0; i < n; i++) {
            cin >> reservationTable[i];
        }

        int clocks = 1;
        int tasks = 0;
        vector<int> busyUnits(n, 0);

        while (tasks < 10) {
            bool conflict = false;
            for (int i = 0; i < n; i++) {
                if (busyUnits[i] > 0) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                tasks++;
            }

            for (int i = 0; i < n; i++) {
                if (reservationTable[i][busyUnits[i]] == 'X') {
                    busyUnits[i]++;
                    if (busyUnits[i] == reservationTable[i].size()) {
                        busyUnits[i] = 0;
                    }
                }
            }

            clocks++;
        }

        cout << clocks - 1 << endl; // Subtracting 1 because we're counting the clock cycles from 1
    }

    return 0;
}
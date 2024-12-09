#include <iostream>
#include <cmath>

using namespace std;

int findTimeToClean(int n, int m, int rb, int cb, int rd, int cd) {
    int time = 0;

    while (rb != rd || cb != cd) {
        if (rb != rd) {
            rb += (rb < rd) ? 1 : -1;
            time++;
        }

        if (cb != cd) {
            cb += (cb < cd) ? 1 : -1;
            time++;
        }

        if (rb == rd && cb == cd) {
            break;
        }

        if (cb == 1 || cb == m) {
            time++;
        }

        if (rb == 1 || rb == n) {
            time++;
        }
    }

    return time;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;

        int time = findTimeToClean(n, m, rb, cb, rd, cd);
        cout << time << endl;
    }

    return 0;
}
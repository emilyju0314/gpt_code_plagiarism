#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;

        int time = 0;
        // simulate the movements of the robot
        while (rb != rd || cb != cd) {
            // update row movement
            if (rb < rd) {
                rb++;
            } else if (rb > rd) {
                rb--;
            }

            // update column movement
            if (cb < cd) {
                cb++;
            } else if (cb > cd) {
                cb--;
            }

            time++;
        }

        cout << time << endl;
    }

    return 0;
}
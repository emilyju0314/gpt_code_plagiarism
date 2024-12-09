#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;

        // Calculate the time to clean the dirty cell
        int time = 0;
        while(rb != rd || cb != cd) {
            if(rb != rd) {
                if(rb < rd) {
                    rb++;
                } else {
                    rb--;
                }
            }
            if(cb != cd) {
                if(cb < cd) {
                    cb++;
                } else {
                    cb--;
                }
            }
            // Reflect dr and dc if the robot reaches a wall
            if(rb == 0 || rb == n+1) {
                rb += (rb == 0) ? 2 : -2;
            }
            if(cb == 0 || cb == m+1) {
                cb += (cb == 0) ? 2 : -2;
            }
            time++;
        }

        cout << time << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;

        int time = 0;
        int dr = 1, dc = 1;

        while(rb != rd || cb != cd) {
            if(rb != rd) {
                int diff = abs(rb - rd);
                if(rb < rd && dr == -1) {
                    dr = -dr;
                    time++;
                } else if(rb > rd && dr == 1) {
                    dr = -dr;
                    time++;
                }
                time += diff;
                rb = rd;
            } else {
                int diff = abs(cb - cd);
                if(cb < cd && dc == -1) {
                    dc = -dc;
                    time++;
                } else if(cb > cd && dc == 1) {
                    dc = -dc;
                    time++;
                }
                time += diff;
                cb = cd;
            }
        }

        cout << time << endl;
    }

    return 0;
}
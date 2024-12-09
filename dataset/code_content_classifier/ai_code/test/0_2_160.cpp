#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;

        int time = abs(rb - rd) + abs(cb - cd); // initial time for cleaning

        if(rb != rd && cb != cd) { // need to move diagonally
            time += 2;
        }

        cout << time << endl;
    }

    return 0;
}
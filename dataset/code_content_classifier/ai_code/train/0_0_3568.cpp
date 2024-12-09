#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int h, c, t;
        cin >> h >> c >> t;

        if (h == t) {
            cout << 1 << endl;
            continue;
        }
        
        int numCups = 2;
        double minDiff = abs(static_cast<double>(h + c) / 2.0 - t);
        
        int cups = 2;
        while (true) {
            double temp = static_cast<double>(h * cups - c * (cups - 1)) / (2 * cups - 1);
            double diff = abs(temp - t);
            if (diff < minDiff) {
                minDiff = diff;
                numCups = cups;
            } else {
                break;
            }
            cups++;
        }

        cout << numCups << endl;
    }

    return 0;
}
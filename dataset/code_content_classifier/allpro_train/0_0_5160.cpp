#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double minTime = -1;
    for (int i = 0; i < n; i++) {
        int rix, riy, vix, viy;
        cin >> rix >> riy >> vix >> viy;

        double firstTimeMovedX = -1, lastTimeMovedX = -1;
        double firstTimeMovedY = -1, lastTimeMovedY = -1;
        if (vix != 0) {
            if (vix > 0) {
                firstTimeMovedX = (x1 - rix) / (double)vix;
                lastTimeMovedX = (x2 - rix) / (double)vix;
            } else {
                firstTimeMovedX = (x2 - rix) / (double)vix;
                lastTimeMovedX = (x1 - rix) / (double)vix;
            }
        }

        if (viy != 0) {
            if (viy > 0) {
                firstTimeMovedY = (y1 - riy) / (double)viy;
                lastTimeMovedY = (y2 - riy) / (double)viy;
            } else {
                firstTimeMovedY = (y2 - riy) / (double)viy;
                lastTimeMovedY = (y1 - riy) / (double)viy;
            }
        }

        double firstTime = max(firstTimeMovedX, firstTimeMovedY);
        double lastTime = min(lastTimeMovedX, lastTimeMovedY);

        if ((firstTime > 0 && lastTime >= firstTime) && (minTime == -1 || firstTime < minTime)) {
            minTime = firstTime;
        }
    }

    cout.precision(20);
    cout << minTime << endl;

    return 0;
}
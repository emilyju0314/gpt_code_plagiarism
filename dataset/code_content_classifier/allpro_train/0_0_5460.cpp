#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;

    // Calculate the minimum and maximum x, y coordinates
    int minX = min({xA, xB, xC});
    int minY = min({yA, yB, yC});
    int maxX = max({xA, xB, xC});
    int maxY = max({yA, yB, yC});

    // Output the number of plots needed to be cleaned
    int numPlots = (maxX - minX + 1) + (maxY - minY + 1);
    cout << numPlots << endl;

    // Output the coordinates of the cleaned plots
    for (int y = minY; y <= maxY; y++) {
        cout << minX << " " << y << endl;
    }
    for (int x = minX + 1; x <= maxX; x++) {
        cout << x << " " << maxY << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA >> xB >> yB >> xC >> yC;

    int minX = min(xA, min(xB, xC));
    int maxX = max(xA, max(xB, xC));
    int minY = min(yA, min(yB, yC));
    int maxY = max(yA, max(yB, yC));

    int k = (maxX - minX + 1) + (maxY - minY + 1);
    cout << k << endl;

    for (int i = minX; i <= maxX; i++) {
        cout << i << " " << minY << endl;
    }
    for (int j = minY + 1; j <= maxY; j++) {
        cout << maxX << " " << j << endl;
    }

    return 0;
}
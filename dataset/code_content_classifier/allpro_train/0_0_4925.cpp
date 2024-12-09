#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x1, y1, z1, x2, y2, z2;
    cin >> n;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    // Calculate the minimum time to reach the treasure
    int min_time = abs(x2 - x1) + abs(y2 - y1) + abs(z2 - z1);
    // Check if rotating along x, y, or z axis would reduce the time
    min_time = min(min_time, min(abs(x2 - x1) + 2, min(abs(y2 - y1) + 2, abs(z2 - z1) + 2)));

    cout << min_time << endl;

    return 0;
}
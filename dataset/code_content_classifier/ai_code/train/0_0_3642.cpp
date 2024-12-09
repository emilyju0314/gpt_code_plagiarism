#include <iostream>

using namespace std;

int main() {
    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int time_stairs = abs(x - y) * t1;
    int time_elevator = (abs(x - z) + abs(x - y)) * t2 + 3 * t3;

    if (time_elevator <= time_stairs) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
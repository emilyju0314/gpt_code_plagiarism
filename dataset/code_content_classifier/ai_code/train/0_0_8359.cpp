#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int distance = 0;

    if (x1 == x2) {
        distance = abs(y1 - y2);
    } else if (y1 == y2) {
        distance = abs(x1 - x2);
    } else {
        distance = abs(x1 - x2) + abs(y1 - y2) + 2;
    }

    cout << distance << endl;

    return 0;
}
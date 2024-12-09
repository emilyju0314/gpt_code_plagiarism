#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2, r;
        cin >> x1 >> y1 >> x2 >> y2 >> r;

        double dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        if (dist <= r) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
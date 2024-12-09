#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

long long min_cost(int x, int y, int c1, int c2, int c3, int c4, int c5, int c6) {
    long long abs_x = abs(x);
    long long abs_y = abs(y);

    long long cost = 0;

    if (abs_x < abs_y) {
        swap(abs_x, abs_y);
        swap(c1, c3);
        swap(c2, c6);
        swap(c3, c5);
    }

    if (x * y > 0) {
        cost += min(abs_x * c2 + abs(y - x) * c3, abs_x * c6 + y * c1);
    } else {
        cost += abs_x * min(c2, c6) + abs_y * c5;
    }

    return cost;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x, y, c1, c2, c3, c4, c5, c6;
        cin >> x >> y;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        cout << min_cost(x, y, c1, c2, c3, c4, c5, c6) << endl;
    }

    return 0;
}
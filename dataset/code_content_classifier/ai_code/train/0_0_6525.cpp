#include <iostream>

using namespace std;

int main() {
    long long x, y, m;
    cin >> x >> y >> m;

    if (x >= m || y >= m) {
        cout << 0 << endl;
    } else if (x <= 0 && y <= 0) {
        cout << -1 << endl;
    } else {
        if (x > y) {
            swap(x, y);
        }
        long long operations = 0;
        while (y < m) {
            if (x < 0) {
                long long temp = x;
                x = y;
                y = temp + y;
            } else {
                x = y;
                y += x;
            }
            operations++;
        }
        cout << operations << endl;
    }

    return 0;
}
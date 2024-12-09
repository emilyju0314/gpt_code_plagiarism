#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x, y, k;
        cin >> x >> y >> k;

        long long sticks_needed = k * y + k;
        long long trades_needed = (sticks_needed + x - 2) / (x - 1); // Using integer division to round up

        cout << trades_needed + k << endl;
    }

    return 0;
}
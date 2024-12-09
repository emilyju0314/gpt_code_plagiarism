#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m > 0) {
        cout << "Impossible" << endl;
    } else {
        int min_fare, max_fare;
        if (n >= m) {
            min_fare = n;
            max_fare = n + (m - 1);
        } else {
            min_fare = n + (m - n);
            max_fare = n + (m - 1);
        }

        cout << min_fare << " " << max_fare << endl;
    }

    return 0;
}
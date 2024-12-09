#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Calculate the number of teleporters needed
    int k = (n * m - 2) / 2;

    cout << k << endl;

    // Output the teleporter coordinates and destinations
    for (int i = 1; i <= k; i++) {
        cout << n << " " << m - i + 1 << " 1 1" << endl;
    }

    // Output the travel path
    cout << "1 1" << endl;

    // Travel to the right edge
    for (int j = 2; j <= m; j++) {
        cout << "1 " << j << endl;
    }

    // Travel to the bottom-right corner
    for (int i = 2; i <= n; i++) {
        cout << i << " " << m << endl;
    }

    // Travel to the top-right corner
    for (int j = m - 1; j >= 1; j--) {
        cout << n << " " << j << endl;
    }

    // Travel back to the capital
    cout << "1 1" << endl;

    return 0;
}
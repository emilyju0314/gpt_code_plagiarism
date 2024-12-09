#include <iostream>
using namespace std;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int dist;
    cin >> dist;
    return dist;
}

int main() {
    int l = 1, r = 1e9;

    // Find the smallest x-coordinate of the enemy base
    while (l < r) {
        int m = (l + r) / 2;
        if (ask(m, 1) != -1) {  // Check the left edge of the grid
            r = m;
        } else {
            l = m + 1;
        }
    }
    int x1 = l; // Smallest x-coordinate

    l = 1, r = 1e9;

    // Find the largest x-coordinate of the enemy base
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (ask(m, 1) != -1) {  // Check the left edge of the grid
            l = m;
        } else {
            r = m - 1;
        }
    }
    int x2 = r; // Largest x-coordinate

    l = 1, r = 1e9;

    // Find the smallest y-coordinate of the enemy base
    while (l < r) {
        int m = (l + r) / 2;
        if (ask(1, m) != -1) {  // Check the top edge of the grid
            r = m;
        } else {
            l = m + 1;
        }
    }
    int y1 = l; // Smallest y-coordinate

    l = 1, r = 1e9;

    // Find the largest y-coordinate of the enemy base
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (ask(1, m) != -1) {  // Check the top edge of the grid
            l = m;
        } else {
            r = m - 1;
        }
    }
    int y2 = r; // Largest y-coordinate

    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();

    return 0;
}
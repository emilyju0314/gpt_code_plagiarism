#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    while (true) {
        // Ciel's turn
        if (x >= 2 && y >= 2) {
            x -= 2;
            y -= 2;
        } else if (x >= 1 && y >= 12) {
            x -= 1;
            y -= 12;
        } else if (y >= 22) {
            y -= 22;
        } else {
            cout << "Hanako" << endl;
            break;
        }

        // Hanako's turn
        if (x >= 2 && y >= 2) {
            x -= 2;
            y -= 2;
        } else if (x >= 1 && y >= 12) {
            x -= 1;
            y -= 12;
        } else if (y >= 22) {
            y -= 22;
        } else {
            cout << "Ciel" << endl;
            break;
        }
    }

    return 0;
}
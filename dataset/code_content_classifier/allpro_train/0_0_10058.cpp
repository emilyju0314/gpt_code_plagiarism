#include <iostream>
using namespace std;

int main() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    // Determine which knight to play with based on their starting positions
    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << "WHITE" << endl;
        cout << n/2 << " " << m/2 << endl;
        cout.flush();

        // Check if the white knight won
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1) {
            return 0;
        } else {
            cout << -1 << " " << -1 << endl;
            cout.flush();
        }
    } else {
        cout << "BLACK" << endl;
        cout.flush();

        // Get the opponent's move
        int x, y;
        cin >> x >> y;

        // Make the move for the black knight
        if (abs(x - n/2) < abs(y - m/2)) {
            cout << x + 2 * (x - n/2) << " " << y + (y < m/2 ? 1 : -1) << endl;
            cout.flush();
        } else {
            cout << x + (x < n/2 ? 1 : -1) << " " << y + 2 * (y - m/2) << endl;
            cout.flush();
        }

        // Check if the black knight won
        cin >> x >> y;
        if (x == -1 && y == -1) {
            return 0;
        } else {
            cout << -1 << " " << -1 << endl;
            cout.flush();
        }
    }

    return 0;
}
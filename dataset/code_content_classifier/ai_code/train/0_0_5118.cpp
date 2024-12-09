#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    // Function to check if a position is inside the chessboard
    auto is_inside = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    // Function to check if a knight can move to a position
    auto can_move = [&](int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2) == 3 && is_inside(x2, y2);
    };

    // Function to print a move
    auto print_move = [&](int x, int y) {
        cout << x << " " << y << endl;
        cout.flush();
    };

    // Check if the player is white or black
    bool is_white = (x1 + y1) % 2 == (x2 + y2) % 2;
    string player = is_white ? "WHITE" : "BLACK";

    if (is_white) {
        // White knight
        if (can_move(x1, y1, n/2, m/2)) {
            cout << player << endl;
            print_move(n/2, m/2);
            return 0;
        } else {
            // Make a random move
            print_move(n/2, m/2);
            print_move(n/2-1, m/2-2);
        }
    } else {
        // Black knight
        if (can_move(x2, y2, n/2 + 1, m/2)) {
            cout << player << endl;
            return 0;
        } else {
            // Make a random move
            print_move(n/2 + 1, m/2);
            print_move(n/2 + 1, m/2 + 2);
        }
    }

    // Main game loop
    for (int i = 0; i < 174; i++) {
        int px, py;
        cin >> px >> py;
        if (px == -1 && py == -1) {
            break;
        }

        if (is_white) {
            // White's turn
            int x = n/2 - 1, y = m/2 - 3;
            while (!can_move(px, py, x, y)) {
                x--;
                if (x < 1) {
                    x = n/2 - 1;
                    y++;
                }
            }
            print_move(x, y);
        } else {
            // Black's turn
            int x = n/2 + 1, y = m/2 + 3;
            while (!can_move(px, py, x, y)) {
                x++;
                if (x > n) {
                    x = n/2 + 1;
                    y--;
                }
            }
            print_move(x, y);
        }
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
    string walls[9];
    for (int i = 0; i < 9; i++) {
        cin >> walls[i];
    }

    // Starting position at point A
    int x = 0, y = 0;
    while (y < 8) {
        // Move right as long as there is no wall
        while (walls[y][x + 1] == '0') {
            cout << "R";
            x++;
        }
        // Move down
        cout << "D";
        y++;

        // Move left as long as there is no wall
        while (walls[y][x - 1] == '0') {
            cout << "L";
            x--;
        }
        // Move down
        cout << "D";
        y++;
    }

    // Return to point A
    cout << "U";
    y--;
    while (x > 0) {
        cout << "L";
        x--;
    }
    cout << "U";
    
    return 0;
}
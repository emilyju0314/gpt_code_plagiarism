#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum Direction { UP, RIGHT, DOWN, LEFT };
const vector<pair<int, int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool isValidPosition(char c) {
    return c != '#' && c != ' ';
}

bool canAccomplishMission(vector<string>& house) {
    int row = 0, col = 0;
    Direction direction = RIGHT;

    while (true) {
        char currentPos = house[row][col];

        if (currentPos == 'M') {
            break;
        }
        
        if (currentPos == '#') {
            direction = static_cast<Direction>((direction + 1) % 4);
        } else {
            house[row][col] = ' ';

            row += directions[direction].first;
            col += directions[direction].second;

            if (row < 0 || col < 0 || row >= house.size() || col >= house[0].size()) {
                return false;
            }
        }
    }

    row = 0;
    col = 0;
    direction = RIGHT;

    while (true) {
        char currentPos = house[row][col];

        if (currentPos == 'K') {
            return true;
        }
        
        if (currentPos == '#') {
            direction = static_cast<Direction>((direction + 1) % 4);
        } else {
            house[row][col] = ' ';

            row += directions[direction].first;
            col += directions[direction].second;

            if (row < 0 || col < 0 || row >= house.size() || col >= house[0].size()) {
                return false;
            }
        }
    }

    return false;
}

int main() {
    int W, H;

    while (cin >> W >> H) {
        if (W == 0 && H == 0) {
            break;
        }

        cin.ignore(); // ignore newline char

        vector<string> house(H);
        for (int i = 0; i < H; i++) {
            getline(cin, house[i]);
        }

        if (canAccomplishMission(house)) {
            cout << "He can accomplish his mission." << endl;
        } else {
            cout << "He cannot bring tea to his master." << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int m, n;
    string command;

    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }

        int x = 1, y = 1; // initial position at (1, 1)
        int direction = 0; // 0: north, 1: east, 2: south, 3: west

        getline(cin, command);

        while (command != "STOP") {
            if (command.substr(0, 7) == "FORWARD") {
                int k = stoi(command.substr(8));
                if (direction == 0) {
                    y = min(n, y + k);
                } else if (direction == 1) {
                    x = min(m, x + k);
                } else if (direction == 2) {
                    y = max(1, y - k);
                } else {
                    x = max(1, x - k);
                }
            } else if (command.substr(0, 8) == "BACKWARD") {
                int k = stoi(command.substr(9));
                if (direction == 0) {
                    y = max(1, y - k);
                } else if (direction == 1) {
                    x = max(1, x - k);
                } else if (direction == 2) {
                    y = min(n, y + k);
                } else {
                    x = min(m, x + k);
                }
            } else if (command == "RIGHT") {
                direction = (direction + 1) % 4;
            } else { // LEFT
                direction = (direction + 3) % 4;
            }

            getline(cin, command);
        }

        cout << x << " " << y << endl;
    }

    return 0;
}
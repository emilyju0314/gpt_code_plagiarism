#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        int top = 1, north = 2, west = 3, east = 4, south = 5, bottom = 6;

        for (int i = 0; i < n; i++) {
            string command;
            cin >> command;

            if (command == "north") {
                int tmp = top;
                top = south;
                south = bottom;
                bottom = north;
                north = tmp;
            } else if (command == "east") {
                int tmp = top;
                top = west;
                west = bottom;
                bottom = east;
                east = tmp;
            } else if (command == "south") {
                int tmp = top;
                top = north;
                north = bottom;
                bottom = south;
                south = tmp;
            } else if (command == "west") {
                int tmp = top;
                top = east;
                east = bottom;
                bottom = west;
                west = tmp;
            }
        }

        cout << top << endl;
    }

    return 0;
}
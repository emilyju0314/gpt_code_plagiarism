#include <iostream>
#include <string>
using namespace std;

struct Dice {
    enum {
        TOP,
        NORTH,
        WEST,
        SOUTH,
        EAST,
        BOTTOM
    };
    int spots[6];

    Dice() {
        spots[TOP] = 1;
        spots[NORTH] = 2;
        spots[WEST] = 3;
        spots[SOUTH] = 5;
        spots[EAST] = 4;
        spots[BOTTOM] = 6;
    }

    int top() {
        return spots[TOP];
    }

    void rotate(string dir) {
        if (dir == "north") {
            rotate_north();
        } else if (dir == "west") {
            rotate_west();
        } else if (dir == "south") {
            rotate_south();
        } else if (dir == "east") {
            rotate_east();
        } else {
            cerr << "ERROR" << endl;
        }
    }
    void rotate_north() {
        int nspots[6];
        nspots[TOP] = spots[SOUTH];
        nspots[NORTH] = spots[TOP];
        nspots[WEST] = spots[WEST];
        nspots[SOUTH] = spots[BOTTOM];
        nspots[EAST] = spots[EAST];
        nspots[BOTTOM] = spots[NORTH];
        for (int i = 0; i < 6; i++) spots[i] = nspots[i];
    }
    void rotate_south() {
        int nspots[6];
        nspots[SOUTH] = spots[TOP];
        nspots[TOP] = spots[NORTH];
        nspots[WEST] = spots[WEST];
        nspots[BOTTOM] = spots[SOUTH];
        nspots[EAST] = spots[EAST];
        nspots[NORTH] = spots[BOTTOM];
        for (int i = 0; i < 6; i++) spots[i] = nspots[i];
    }
    void rotate_west() {
        int nspots[6];
        nspots[SOUTH] = spots[SOUTH];
        nspots[TOP] = spots[EAST];
        nspots[WEST] = spots[TOP];
        nspots[BOTTOM] = spots[WEST];
        nspots[EAST] = spots[BOTTOM];
        nspots[NORTH] = spots[NORTH];
        for (int i = 0; i < 6; i++) spots[i] = nspots[i];
    }
    void rotate_east() {
        int nspots[6];
        nspots[SOUTH] = spots[SOUTH];
        nspots[EAST] = spots[TOP];
        nspots[TOP] = spots[WEST];
        nspots[WEST] = spots[BOTTOM];
        nspots[BOTTOM] = spots[EAST];
        nspots[NORTH] = spots[NORTH];
        for (int i = 0; i < 6; i++) spots[i] = nspots[i];
    }
};

int main() {
    int n;
    while (cin >> n, n) {
        string dir;
        Dice d;
        for (int i = 0; i < n; i++) {
            cin >> dir;
            d.rotate(dir);
        }
        cout << d.top() << endl;
    }
    return 0;
}
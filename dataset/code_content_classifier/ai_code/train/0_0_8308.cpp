#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canOpenDoor(int W, int H, vector<string>& roomL, vector<string>& roomR) {
    int destX, destY;
    int leftX, leftY;
    int rightX, rightY;

    // Find destination coordinates
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (roomL[i][j] == '%' || roomR[i][j] == '%') {
                destX = j;
                destY = i;
            }
            if (roomL[i][j] == 'L') {
                leftX = j;
                leftY = i;
            }
            if (roomR[i][j] == 'R') {
                rightX = j;
                rightY = i;
            }
        }
    }

    // Symmetrical movement
    while (true) {
        // Check if both twins are at the destination
        if (leftX == destX && leftY == destY && rightX == destX && rightY == destY) {
            return true;
        }

        // Check if they can't move
        if (roomL[leftY][leftX] == '#' && roomR[rightY][rightX] == '#') {
            return false;
        }

        // Move left twin
        if (leftX > 0 && roomL[leftY][leftX - 1] != '#') {
            leftX--;
        }

        // Move right twin
        if (rightX < W - 1 && roomR[rightY][rightX + 1] != '#') {
            rightX++;
        }
    }
}

int main() {
    int W, H;

    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) {
            break;
        }

        vector<string> roomL(H);
        vector<string> roomR(H);

        for (int i = 0; i < H; i++) {
            cin >> roomL[i] >> roomR[i];
        }

        if (canOpenDoor(W, H, roomL, roomR)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
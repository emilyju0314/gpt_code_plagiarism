#include <iostream>
using namespace std;

int main() {
    int startX, startY, numMoves;
    cin >> startX >> startY >> numMoves;

    int posX = startX, posY = startY;
    char direction = 'N';

    for (int i = 0; i < numMoves; i++) {
        int move;
        char newDirection;
        cin >> move >> newDirection;

        if (newDirection == 'E') {
            posX += move;
        } else if (newDirection == 'W') {
            posX -= move;
        } else if (newDirection == 'N') {
            posY += move;
        } else if (newDirection == 'S') {
            posY -= move;
        }

        direction = newDirection;
    }

    cout << abs(startX - posX) + abs(startY - posY) << endl;

    return 0;
}
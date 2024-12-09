#include <iostream>
using namespace std;

int main() {
    int closestX = -1, minX, maxX;
    int closestY = -1, minY, maxY;

    // Find the x-coordinate of the left side of the base
    for (int i = 1; i <= 1e9; i += 4) {
        cout << "? " << i << " " << 2 << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            closestX = i;
            break;
        }
    }

    // Find the x-coordinate of the right side of the base
    for (int i = 5; i <= 1e9; i += 4) {
        cout << "? " << i << " " << 2 << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            closestX = i;
            break;
        }
    }

    // Find the y-coordinate of the top side of the base
    for (int i = 1; i <= 1e9; i += 4) {
        cout << "? " << 2 << " " << i << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            closestY = i;
            break;
        }
    }

    // Find the y-coordinate of the bottom side of the base
    for (int i = 5; i <= 1e9; i += 4) {
        cout << "? " << 2 << " " << i << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            closestY = i;
            break;
        }
    }

    // Find the minX and minY
    for (int i = closestX - 2; i <= closestX; ++i) {
        cout << "? " << i << " " << closestY << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            minX = i;
            break;
        }
    }

    for (int i = closestY - 2; i <= closestY; ++i) {
        cout << "? " << closestX << " " << i << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            minY = i;
            break;
        }
    }

    // Find the maxX and maxY
    for (int i = closestX; i <= closestX + 2; ++i) {
        cout << "? " << i << " " << closestY << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            maxX = i;
            break;
        }
    }

    for (int i = closestY; i <= closestY + 2; ++i) {
        cout << "? " << closestX << " " << i << endl;
        int dist;
        cin >> dist;
        if (dist == 0) {
            maxY = i;
            break;
        }
    }

    // Output the result
    cout << "! " << minX << " " << minY << " " << maxX << " " << maxY << endl;

    return 0;
}
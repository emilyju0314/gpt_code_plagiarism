#include <iostream>

using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int dist;
    cin >> dist;
    return dist;
}

int main() {
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

    // Find the smallest x1 and y1 such that query(x1, y1) is not -1
    for (int i = 2; i <= 1000000000; i += 4) {
        int dist = query(i, 2);
        if (dist != -1) {
            x1 = i;
            y1 = 2;
            break;
        }
    }

    // Find the largest x2 and y2 such that query(x2, y2) is not -1
    for (int i = 1000000000; i >= 5; i -= 4) {
        int dist = query(i, 5);
        if (dist != -1) {
            x2 = i;
            y2 = 5;
            break;
        }
    }

    // Output the result
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();

    return 0;
}
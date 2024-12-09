#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    bool possible = false;

    if ((x1 == x2 && y1 == y2) || 
        (x1 == -y2 + x2 && y1 == x2 + y2) || 
        (x1 == -x2 && y1 == -y2) || 
        (x1 == y2 + x2 && y1 == -x2 + y2)) {
        possible = true;
    } else {
        if (x3 != 0 || y3 != 0) {
            if ((x1 - x3 == x2 && y1 - y3 == y2) || 
                (x1 - y3 == -y2 + x2 && y1 - x3 == x2 + y2) || 
                (x1 - x3 == -x2 && y1 - y3 == -y2) || 
                (x1 - y3 == y2 + x2 && y1 - x3 == -x2 + y2)) {
                possible = true;
            } else {
                if ((x1 + x3 == x2 && y1 + y3 == y2) || 
                    (x1 + y3 == -y2 + x2 && y1 + x3 == x2 + y2) || 
                    (x1 + x3 == -x2 && y1 + y3 == -y2) || 
                    (x1 + y3 == y2 + x2 && y1 + x3 == -x2 + y2)) {
                    possible = true;
                }
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
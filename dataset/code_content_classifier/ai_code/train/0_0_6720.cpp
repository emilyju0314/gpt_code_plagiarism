#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int turn = 0;

    while (a >= 0 && b >= 0) {
        if (turn % 2 == 0) {
            a -= (turn + 1);
        } else {
            b -= (turn + 1);
        }
        turn++;

        if (a < 0) {
            cout << "Vladik" << endl;
            break;
        } else if (b < 0) {
            cout << "Valera" << endl;
            break;
        }
    }

    return 0;
}
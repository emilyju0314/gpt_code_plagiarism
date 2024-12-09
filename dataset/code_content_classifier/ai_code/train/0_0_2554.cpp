#include <iostream>
#include <string>

using namespace std;

int getWeight(char piece) {
    switch(piece) {
        case 'Q':
            return 9;
        case 'R':
            return 5;
        case 'B':
            return 3;
        case 'N':
            return 3;
        case 'P':
            return 1;
        case 'q':
            return -9;
        case 'r':
            return -5;
        case 'b':
            return -3;
        case 'n':
            return -3;
        case 'p':
            return -1;
        default:
            return 0;
    }
}

int main() {
    int whiteWeight = 0;
    int blackWeight = 0;

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < 8; j++) {
            whiteWeight += getWeight(row[j]);
        }
    }

    if (whiteWeight > 0) {
        cout << "White" << endl;
    } else if (whiteWeight < 0) {
        cout << "Black" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
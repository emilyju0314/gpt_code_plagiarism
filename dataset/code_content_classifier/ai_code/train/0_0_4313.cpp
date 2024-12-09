#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    string colors;
    cin >> colors;

    bool hasPink = false, hasWhite = false, hasGreen = false, hasYellow = false;

    for (char c : colors) {
        if (c == 'P') {
            hasPink = true;
        } else if (c == 'W') {
            hasWhite = true;
        } else if (c == 'G') {
            hasGreen = true;
        } else if (c == 'Y') {
            hasYellow = true;
        }
    }

    if (hasYellow) {
        cout << "Four" << endl;
    } else {
        cout << "Three" << endl;
    }

    return 0;
}
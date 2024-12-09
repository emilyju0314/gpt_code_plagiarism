#include <iostream>

using namespace std;

int getGroup(int num) {
    if (num == 1 || num == 3 || num == 5 || num == 7 || num == 8 || num == 10 || num == 12) {
        return 1;
    } else if (num == 4 || num == 6 || num == 9 || num == 11) {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    int x, y;
    cin >> x >> y;

    if (getGroup(x) == getGroup(y)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
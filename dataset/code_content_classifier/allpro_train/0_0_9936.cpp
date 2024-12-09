#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int kyu;
    if (X >= 400 && X <= 599) {
        kyu = 8;
    } else if (X >= 600 && X <= 799) {
        kyu = 7;
    } else if (X >= 800 && X <= 999) {
        kyu = 6;
    } else if (X >= 1000 && X <= 1199) {
        kyu = 5;
    } else if (X >= 1200 && X <= 1399) {
        kyu = 4;
    } else if (X >= 1400 && X <= 1599) {
        kyu = 3;
    } else if (X >= 1600 && X <= 1799) {
        kyu = 2;
    } else {
        kyu = 1;
    }

    cout << kyu << endl;

    return 0;
}
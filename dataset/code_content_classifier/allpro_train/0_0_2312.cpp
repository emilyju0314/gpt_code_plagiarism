#include <iostream>
using namespace std;

bool isLucky(int h, int m) {
    return (h/10 == 7 || h%10 == 7 || m/10 == 7 || m%10 == 7);
}

int main() {
    int x, hh, mm;
    cin >> x >> hh >> mm;

    int totalMins = hh * 60 + mm;
    int buttonPresses = 0;

    while (!isLucky(totalMins / 60, totalMins % 60)) {
        buttonPresses++;
        totalMins = (totalMins - x + 1440) % 1440; // Add 1440 to avoid negative numbers
    }

    cout << buttonPresses << endl;

    return 0;
}
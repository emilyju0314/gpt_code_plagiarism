#include <iostream>
using namespace std;

int main() {
    string x;
    cin >> x;

    bool leadingZeros = true;

    for (int i = 0; i < x.length(); i++) {
        int digit = x[i] - '0';
        if (leadingZeros && digit == 9) {
            cout << 9;
        } else {
            if (9 - digit < digit) {
                cout << 9 - digit;
                leadingZeros = false;
            } else {
                cout << digit;
                if (digit != 0) {
                    leadingZeros = false;
                }
            }
        }
    }

    return 0;
}
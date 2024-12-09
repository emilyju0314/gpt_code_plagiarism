#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int zeros = 0, ones = 0, twos = 0;
    for (char c : s) {
        if (c == '0') {
            zeros++;
        } else if (c == '1') {
            ones++;
        } else {
            twos++;
        }
    }

    string result = "";
    for (int i = 0; i < zeros; i++) {
        result += '0';
    }
    for (int i = 0; i < ones; i++) {
        result += '1';
    }
    for (int i = 0; i < twos; i++) {
        result += '2';
    }

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    cin >> number;

    int decimalPointIndex = number.find(".");
    string integerPart = number.substr(0, decimalPointIndex);
    string fractionalPart = number.substr(decimalPointIndex + 1);

    if (integerPart[integerPart.size() - 1] != '9') {
        if (fractionalPart[0] < '5') {
            cout << integerPart << endl;
        } else {
            int lastDigit = integerPart[integerPart.size() - 1] - '0';
            cout << integerPart.substr(0, integerPart.size() - 1) << lastDigit + 1 << endl;
        }
    } else {
        cout << "GOTO Vasilisa" << endl;
    }

    return 0;
}
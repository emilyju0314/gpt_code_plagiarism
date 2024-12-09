#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

double binaryToDecimal(string binary) {
    int sign = (binary[0] == '1') ? -1 : 1;
    int integerPart = 0;
    double decimalPart = 0.0;

    for (int i = 8; i < 32; i++) {
        integerPart += (binary[i] - '0') * pow(2, 23 - (i - 8));
    }

    for (int i = 1; i <= 7; i++) {
        decimalPart += (binary[i] - '0') * pow(0.5, i);
    }

    return sign * (integerPart + decimalPart);
}

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        string binary;
        cin >> binary;

        double result = binaryToDecimal(binary);
        cout << fixed << setprecision(3) << result << endl;
    }

    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

string toBinaryString(long long num) {
    string binary = "";
    while (num > 0) {
        binary = to_string(num % 2) + binary;
        num /= 2;
    }
    return binary;
}

long long fromBinaryString(string binary) {
    reverse(binary.begin(), binary.end());
    long long num = 0;
    for (int i = 0; i < binary.length(); i++) {
        num += (binary[i] - '0') * (1LL << i);
    }
    return num;
}

bool canTurnInto(long long x, long long y) {
    if (x == y) {
        return true;
    }

    string binary_x = toBinaryString(x);
    string binary_y = toBinaryString(y);

    while (binary_x.length() < binary_y.length()) {
        binary_x = '0' + binary_x;
    }

    int diff = binary_x.length() - binary_y.length();

    if (binary_x.substr(diff) == binary_y) {
        return true;
    }

    return false;
}

int main() {
    long long x, y;
    cin >> x >> y;

    if (canTurnInto(x, y)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

unsigned long long convertToDecimal(const string& num, int base) {
    unsigned long long result = 0;
    for (char c : num) {
        result = result * base + (c - '0');
    }
    return result;
}

int main() {
    int n;
    string k;
    cin >> n >> k;

    unsigned long long x = convertToDecimal(k, n);
    cout << x << endl;

    return 0;
}
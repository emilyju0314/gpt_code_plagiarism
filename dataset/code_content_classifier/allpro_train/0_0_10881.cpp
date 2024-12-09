#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    int lastDigit = 1;
    for (long long i = a + 1; i <= b; i++) {
        int digit = i % 10;
        lastDigit = (lastDigit * digit) % 10;
        if (lastDigit == 0) break;
    }

    cout << lastDigit << endl;

    return 0;
}
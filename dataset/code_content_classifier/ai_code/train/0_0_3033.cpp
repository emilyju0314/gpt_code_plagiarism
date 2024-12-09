#include <iostream>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int d, s;
    cin >> d >> s;

    for (int i = 1; i <= 5000; i++) {
        if (i % d == 0 && sumOfDigits(i) == s) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
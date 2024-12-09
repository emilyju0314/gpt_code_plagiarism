#include <iostream>
#include <string>

using namespace std;

int sumOfDigits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int a = 1; a <= 10000; a++) {
        for (int b = 1; b <= 10000; b++) {
            if (sumOfDigits(a) >= n && sumOfDigits(b) >= n && sumOfDigits(a + b) <= m) {
                cout << a << endl;
                cout << b << endl;
                return 0;
            }
        }
    }

    return 0;
}
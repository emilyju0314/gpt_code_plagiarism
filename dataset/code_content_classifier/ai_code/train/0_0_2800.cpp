#include <iostream>
using namespace std;

bool isRotatable(int num, int base) {
    for (int i = 1; i <= num; i++) {
        int rotated = 0;
        int temp = num;
        for (int j = 0; j < i; j++) {
            rotated *= base;
            rotated += temp % base;
            temp /= base;
        }
        if (rotated != num) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, x;
    cin >> n >> x;

    for (int b = x - 1; b > 1; b--) {
        if (isRotatable(n, b)) {
            cout << b << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
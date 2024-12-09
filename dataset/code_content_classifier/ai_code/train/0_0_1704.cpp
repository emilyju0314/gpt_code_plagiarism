#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int X2;
    cin >> X2;

    int X1;
    for (X1 = X2 - 1; !isPrime(X1); X1--) {}
    int X0 = X1 - 1;
    cout << X0 << endl;

    return 0;
}
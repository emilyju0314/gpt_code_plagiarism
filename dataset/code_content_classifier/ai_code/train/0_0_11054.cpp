#include <iostream>

using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, k;
    cin >> n >> k;

    int result = 0;
    for (int i = 0; i <= k; i++) {
        result += nCr(n, i) * factorial(n - i);
    }

    cout << result << endl;

    return 0;
}
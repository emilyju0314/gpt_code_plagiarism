#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int A, B;
    cin >> A >> B;

    int factA = factorial(A);
    int factB = factorial(B);

    int result = gcd(factA, factB);

    cout << result << endl;

    return 0;
}
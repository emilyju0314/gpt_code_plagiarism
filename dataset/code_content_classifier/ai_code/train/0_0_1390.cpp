#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    // Find the minimum m such that nCm is even
    // nCm is even when n is not equal to 2^k for any non-negative integer k
    int m = 0;
    for (int i = 0; i <= 60; i++) {
        if ((n >> i) % 2 == 1) {
            m = i;
            break;
        }
    }

    cout << m << endl;

    return 0;
}
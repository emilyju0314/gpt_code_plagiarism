#include <iostream>

using namespace std;

int countBits(long long n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    long long m, k;
    cin >> m >> k;

    long long n = 0;
    for (long long i = 1; i <= 1018; i++) {
        long long count = 0;
        for (long long j = i + 1; j <= 2 * i; j++) {
            if (countBits(j) == k) {
                count++;
            }
        }
        if (count == m) {
            n = i;
            break;
        }
    }

    cout << n << endl;

    return 0;
}
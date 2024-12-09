#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        int count = 0;
        for (int x = l; x <= r; x += 2) {
            if (isPrime(x) && isPrime((x+1)/2)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
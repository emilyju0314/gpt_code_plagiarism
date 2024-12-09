#include <iostream>

using namespace std;

long long calculateFinalPosition(long long x0, long long n) {
    long long sum = n * (n + 1) / 2;
    
    if (x0 % 2 == 0) {
        if (sum % 2 == 0) {
            return x0 + sum;
        } else {
            return x0 - sum;
        }
    } else {
        if (sum % 2 == 0) {
            return x0 - sum;
        } else {
            return x0 + sum;
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x0, n;
        cin >> x0 >> n;

        cout << calculateFinalPosition(x0, n) << endl;
    }

    return 0;
}
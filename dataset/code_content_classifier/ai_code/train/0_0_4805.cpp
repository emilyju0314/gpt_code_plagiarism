#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    // If n is even, subtract 2 to make it odd
    if (n % 2 == 0) {
        cout << "3" << endl;
        cout << "2 " << n-2 << " 1" << endl;
    } else {
        // Check if n-2 or n-4 is prime, if not find the first smaller prime
        int a, b, c;
        if (isPrime(n-2)) {
            a = 2;
            b = n-2;
            c = 1;
        } else if (isPrime(n-4)) {
            a = 2;
            b = n-4;
            c = 2;
        } else {
            for (int i = 3; i < n; i += 2) {
                if (isPrime(i) && isPrime(n-i)) {
                    a = i;
                    b = n-i;
                    c = 1;
                    break;
                }
            }
        }

        cout << "3" << endl;
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}
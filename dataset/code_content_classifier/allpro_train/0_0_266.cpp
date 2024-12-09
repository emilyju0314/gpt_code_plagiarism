#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;

    long long a = 1, b = x; // Initialize a and b with 1 and x
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            a = i;
            b = x / i;
            break;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
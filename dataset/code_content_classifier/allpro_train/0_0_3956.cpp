#include <iostream>
#include <cmath>

using namespace std;

int power(int a, int n, int p) {
    int result = 1;
    a = a % p;
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * a) % p;
        n = n / 2;
        a = (a * a) % p;
    }
    return result;
}

int main() {
    int a, b, p;
    long long x;
    cin >> a >> b >> p >> x;

    int count = 0;
    for (int n = 1; n <= x; n++) {
        if ((power(a, n, p) * n) % p == b) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
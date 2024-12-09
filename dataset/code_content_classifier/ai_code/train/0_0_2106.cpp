#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long res = 0;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res += n;
            n /= i;
        }
    }

    if (n != 1) {
        res += n;
    }

    cout << res + 1 << endl;

    return 0;
}
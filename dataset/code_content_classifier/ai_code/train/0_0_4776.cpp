#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result = result / i * (i - 1);
        }
    }
    if (n > 1) {
        result = result / n * (n - 1);
    }

    cout << result << endl;

    return 0;
}  
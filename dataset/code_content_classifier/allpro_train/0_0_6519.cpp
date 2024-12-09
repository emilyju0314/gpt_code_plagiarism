#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result += n;
        }
    }
    if (n > 1) {
        result += 1;
    }

    cout << result << endl;

    return 0;
}
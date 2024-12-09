#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long m = 998244353;
    long long result = 0;
    long long mul = 1;

    while (mul * 10 <= n) {
        result = (result + (9 * mul % m) * mul % m) % 1000000007;
        mul *= 10;
    }

    result = (result + ((n - mul + 1) * mul % m) * (n - mul + 1) % m) % 1000000007;

    cout << result << endl;

    return 0;
}
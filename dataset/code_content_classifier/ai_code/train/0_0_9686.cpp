#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, a, b;
    cin >> n >> a >> b;

    if (a > b || n == 1 && a != b) {
        cout << 0 << endl;
    } else {
        cout << max(0LL, (b - a) * (n - 2) + 1) << endl;
    }

    return 0;
}
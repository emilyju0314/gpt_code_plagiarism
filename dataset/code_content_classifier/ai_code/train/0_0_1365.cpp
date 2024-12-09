#include <iostream>

using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n % m == 0) {
        cout << 0 << endl;
    } else {
        long long rem = n % m;
        long long buildCost = rem * a;
        long long demolishCost = (m - rem) * b;
        cout << min(buildCost, demolishCost) << endl;
    }

    return 0;
}
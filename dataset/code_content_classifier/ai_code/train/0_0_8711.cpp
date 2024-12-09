#include <iostream>

using namespace std;

int main() {
    int m, b;
    cin >> m >> b;

    long long ans = 0;

    for (int y = b; y >= 0; y--) {
        int x = m * (b - y);
        long long bananas = (long long)(x + 1) * (y * (y + 1) / 2) + (x * (x + 1) / 2) * (y + 1);
        ans = max(ans, bananas);
    }

    cout << ans << endl;

    return 0;
}
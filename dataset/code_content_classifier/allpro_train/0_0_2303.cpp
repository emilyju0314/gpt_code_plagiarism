#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    if (y <= x) {
        cout << n * x << endl;
    } else {
        int result = 0;
        if (n % 2 == 0) {
            result = min(n / 2 * y, n * x);
        } else {
            result = min((n-1)/2 * y + x, n * x);
        }
        cout << result << endl;
    }

    return 0;
}
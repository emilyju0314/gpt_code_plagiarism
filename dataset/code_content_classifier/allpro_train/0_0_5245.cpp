#include <iostream>

using namespace std;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    long long result = 2 * x * y * z - x - y - z + 1;
    if (k > 0) {
        result += 2 * (x + y + z - 3) * min(k, (x + y + z - 2));
        if (k > 1) {
            result += 3 * (k - 1) * (k - 1 + x + y + z - 2) / 2;
            if (k > 2) {
                result += 4 * (k - 2) * (k - 1) / 2;
            }
        }
    }

    cout << result << endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int countTrailingZeros(int n) {
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int m;
    cin >> m;

    // Binary search for the minimum value of n
    int low = 0, high = 5 * m, result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (countTrailingZeros(mid) >= m) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (countTrailingZeros(result) == m) {
        cout << 5 << endl;
        for (int i = result; i < result + 5; i++) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
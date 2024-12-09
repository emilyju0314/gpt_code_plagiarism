#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int left = 1, right = n * m;
    int result = 0;

    while (left <= right) {
        int count = 0;
        int mid = (left + right) / 2;

        for (int i = 1; i <= n; i++) {
            count += min(m, mid / i);
        }

        if (count < k) {
            left = mid + 1;
        } else {
            result = mid;
            right = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
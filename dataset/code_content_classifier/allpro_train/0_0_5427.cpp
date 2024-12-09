#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d, b;
    cin >> n >> d >> b;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = b, right = b;
    int max_diff = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > b) {
            if (a[i] - b <= d) {
                left -= b;
            } else {
                left -= a[i] - d;
            }
        } else {
            if (b - a[i] <= d) {
                right -= b;
            } else {
                right -= a[i] + d;
            }
        }
        max_diff = max(max_diff, max(left, right));
    }

    cout << max_diff << endl;

    return 0;
}
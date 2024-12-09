#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long x, y;
    cin >> n >> x >> y;

    if (n == 1) {
        if (y >= x) {
            cout << y << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        long long sum = 0;
        vector<int> ans(n, 1);
        ans[0] = y - (n - 1);
        for (int i = 0; i < n; i++) {
            sum += ans[i] * ans[i];
        }

        if (sum <= x) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
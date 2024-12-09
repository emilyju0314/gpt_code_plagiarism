#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n || (k == 0 && n > 1)) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n - k; i++) {
            cout << i + k + 1 << " ";
        }
        for (int i = 1; i <= k + 1; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        if (n % 2 == 0 && n >= k) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << n / k << " ";
            }
            cout << n - (n / k) * (k - 1) << endl;
        } else if (n % 2 == 1 && n >= k * 2) {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++) {
                cout << 2 << " ";
            }
            cout << n - 2 * (k - 1) << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
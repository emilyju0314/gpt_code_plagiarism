#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even++;
            else odd++;
        }

        if (even != odd) {
            cout << -1 << endl;
            continue;
        }

        int moves = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 != a[i] % 2) {
                moves++;
            }
        }

        cout << moves / 2 << endl;
    }

    return 0;
}
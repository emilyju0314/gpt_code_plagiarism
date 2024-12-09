#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> a(n);
        bool possible = true;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += b[i];
        }

        for (int i = 0; i < n; i++) {
            if (sum - b[i] <= 2 * b[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                a[i] = (i == 0) ? 1 : 2 * b[i-1] - a[i-1];
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
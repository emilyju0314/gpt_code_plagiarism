#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }

        vector<int> p(n, -1);
        int current_max = q[n - 1];
        p[n - 1] = q[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (q[i] != q[i + 1]) {
                current_max = q[i];
                p[i] = q[i];
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (p[i] == -1) {
                if (current_max == 0) {
                    possible = false;
                    break;
                }
                p[i] = current_max--;
            }
        }

        if (possible) {
            for (int i = 0; i < n; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
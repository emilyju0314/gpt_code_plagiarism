#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;

        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        int x = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2 * k; j++) {
                if (d[i] + j <= l) {
                    x = i;
                    break;
                }
            }

            if (x != i) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
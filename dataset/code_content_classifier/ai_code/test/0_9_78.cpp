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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> possible_k;

        for (int k = 1; k <= n; k++) {
            int x = a[0];
            for (int i = 1; i < n; i++) {
                x &= a[i];
            }
            if (x == 0) {
                possible_k.push_back(k);
            }

            if (k < n) {
                for (int i = 0; i < n; i++) {
                    a[i] &= a[(i + 1) % n];
                }
            }
        }

        for (int k : possible_k) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}
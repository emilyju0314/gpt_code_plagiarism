#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

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

        vector<int> possible_ks;
        for (int k = 1; k <= n; k++) {
            bool possible = true;
            for (int bit = 0; bit < 30; bit++) {
                int count = 0;
                for (int i = 0; i < n; i++) {
                    if (a[i] & (1 << bit)) {
                        count++;
                    }
                }
                if (count >= k && count <= n - (k - 1)) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                possible_ks.push_back(k);
            }
        }

        for (int i = 0; i < possible_ks.size(); i++) {
            cout << possible_ks[i];
            if (i != possible_ks.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
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
        vector<int> bits(31, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < 31; j++) {
                if ((a[i] & (1 << j)) != 0) {
                    bits[j]++;
                }
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++) {
            int cur = a[i];
            bool found = false;
            for (int j = 0; j < 31; j++) {
                if ((a[i] & (1 << j)) != 0 && bits[j] == 1) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                possible = false;
                break;
            }
        }

        if (possible) {
            for (int k = 1; k <= n; k++) {
                if (n % k == 0) {
                    bool valid = true;
                    for (int j = 0; j < 31; j++) {
                        int count = 0;
                        for (int i = 0; i < n; i++) {
                            if ((a[i] & (1 << j)) != 0) {
                                count++;
                            }
                        }
                        if (count % k != 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        cout << k << " ";
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}
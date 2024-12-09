#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int oddCount = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 1) {
                oddCount++;
            }
        }

        if (oddCount < k || (oddCount % 2 != k % 2)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (count == k - 1) break;
                if (a[i] % 2 == 1) {
                    cout << i + 1 << " ";
                    count++;
                }
            }
            cout << n << endl;
        }
    }

    return 0;
}
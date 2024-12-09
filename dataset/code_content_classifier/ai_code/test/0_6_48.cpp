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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool canSort = true;

        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1) {
                int j = i;
                while (j < n && a[j] != i + 1) {
                    j++;
                }

                if ((j - i) % 2 == 1) {
                    canSort = false;
                    break;
                }
            }
        }

        if (canSort) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
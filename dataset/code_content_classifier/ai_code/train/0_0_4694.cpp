#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n, 0);
        int action = 1;

        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;

            while (l <= r && a[l] != 0) {
                l++;
            }

            while (r >= l && a[r] != 0) {
                r--;
            }

            int mid = (l + r) / 2;

            if ((r - l + 1) % 2 == 0) {
                mid = (l + r - 1) / 2;
            }

            a[mid] = action;
            action++;
        }

        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> zeros(n, 0);

    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;

        int l = 1, r = n;

        while (l < r) {
            int mid = (l + r) / 2;
            cout << "? " << l << " " << mid << endl;
            cout.flush();

            int cnt_zeros;
            cin >> cnt_zeros;

            int zeros_in_range = mid - l + 1 - cnt_zeros;

            if (zeros_in_range >= k) {
                r = mid;
            } else {
                l = mid + 1;
                k -= zeros_in_range;
            }
        }

        cout << "! " << l << endl;
        cout.flush();

        zeros[l - 1] = 1;
    }

    return 0;
}
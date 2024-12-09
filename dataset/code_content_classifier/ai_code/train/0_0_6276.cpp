#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> lipschitz(n, 0);
    for (int i = 1; i < n; i++) {
        int l = 0;
        int r = 1;

        while (r < n) {
            if (abs(h[r] - h[l]) <= abs(r - l) * i) {
                lipschitz[i]++;
                r++;
            } else {
                l++;
                if (l == r) {
                    r++;
                }
            }
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        long long sum = 0;
        for (int i = l; i < r; i++) {
            sum += lipschitz[i];
        }
        cout << sum << endl;
    }

    return 0;
}
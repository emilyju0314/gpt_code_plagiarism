#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, mod;
    cin >> n >> mod;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for(int j = l-1; j < r; j++) {
                a[j] = (1LL * a[j] * x) % mod;
            }
        } else if (type == 2) {
            int p, x;
            cin >> p >> x;
            a[p-1] = (1LL * a[p-1] / x) % mod;
        } else {
            int l, r;
            cin >> l >> r;
            int sum = 0;
            for(int j = l-1; j < r; j++) {
                sum = (sum + a[j]) % mod;
            }
            cout << sum << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++) {
        int query_type;
        cin >> query_type;

        if(query_type == 1) {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            int sum = 0;
            for(int j = l; j <= r; j++) {
                sum += a[j];
            }

            cout << sum << endl;
        } else {
            int l, r, x;
            cin >> l >> r >> x;

            l--;
            r--;

            for(int j = l; j <= r; j++) {
                a[j] ^= x;
            }
        }
    }

    return 0;
}
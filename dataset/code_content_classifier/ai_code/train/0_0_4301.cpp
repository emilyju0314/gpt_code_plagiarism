#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(a[i] - b[i]);
    }

    cout << sum << endl;

    vector<int> updates(q);
    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        l--;
        r--;

        updates[i] = x;

        for(int j = l; j <= r; j++) {
            a[j] += x;
        }

        sum = 0;
        for(int k = 0; k <= m - n; k++) {
            int temp = 0;
            for(int j = 0; j < n; j++) {
                temp += abs(a[j] - b[j+k]);
            }
            sum = min(sum, temp);
        }

        cout << sum << endl;
    }

    return 0;
}
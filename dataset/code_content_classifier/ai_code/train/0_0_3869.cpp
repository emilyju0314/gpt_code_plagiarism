#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;

        for (int j = l - 1; j <= r - 1; j++) {
            if (a[j] == x) {
                a[j] = y;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
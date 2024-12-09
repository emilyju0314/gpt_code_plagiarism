#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    vector<int> b(n), c(n);
    int minMax = 0;
    for(int i = 0; i < n; i++) {
        minMax = max(minMax, a[i]);
        b[i] = minMax - a[i];
    }

    minMax = 0;
    for(int i = n-1; i >= 0; i--) {
        minMax = max(minMax, a[i]);
        c[i] = minMax - a[i];
    }

    cout << *max_element(b.begin(), b.end()) + *max_element(c.begin(), c.end()) << endl;

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;

        for(int i = l-1; i < r; i++) {
            a[i] += x;
        }

        minMax = 0;
        for(int i = 0; i < n; i++) {
            minMax = max(minMax, a[i]);
            b[i] = minMax - a[i];
        }

        minMax = 0;
        for(int i = n-1; i >= 0; i--) {
            minMax = max(minMax, a[i]);
            c[i] = minMax - a[i];
        }

        cout << *max_element(b.begin(), b.end()) + *max_element(c.begin(), c.end()) << endl;
    }

    return 0;
}
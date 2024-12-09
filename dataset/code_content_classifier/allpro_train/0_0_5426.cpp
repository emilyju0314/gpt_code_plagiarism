#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int D(int x) {
    int count = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            count++;
            if (x / i != i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int q = 0; q < m; q++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            for (int i = l - 1; i < r; i++) {
                a[i] = D(a[i]);
            }
        } else if (t == 2) {
            int sum = 0;
            for (int i = l - 1; i < r; i++) {
                sum += a[i];
            }
            cout << sum << endl;
        }
    }

    return 0;
}
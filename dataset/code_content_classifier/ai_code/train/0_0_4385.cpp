#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> x1(n), x2(n), y1(n), a(n), b(n), y2(n);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i] >> y1[i] >> a[i] >> b[i] >> y2[i];
    }

    cin >> m;

    int last = 0;
    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        long long sum = 0;
        for (int j = l - 1; j < r; j++) {
            int xi = (x + last) % 1000000000;
            if (xi <= x1[j]) {
                sum += y1[j];
            } else if (xi > x1[j] && xi <= x2[j]) {
                sum += a[j]*xi + b[j];
            } else {
                sum += y2[j];
            }
        }

        cout << sum << endl;
        last = sum;
    }

    return 0;
}
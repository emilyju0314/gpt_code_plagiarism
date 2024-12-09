#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            for (int j = 0; j < x; j++) {
                a[j] = max(a[j], y);
            }
        } else {
            int total_meals = 0;
            for (int j = x - 1; j < n; j++) {
                if (y >= a[j]) {
                    y -= a[j];
                    total_meals++;
                } else {
                    break;
                }
            }
            cout << total_meals << endl;
        }
    }

    return 0;
}
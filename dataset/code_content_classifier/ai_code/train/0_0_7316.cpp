#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, r, v;
    cin >> n >> r >> v;

    for (int i = 0; i < n; i++) {
        int si, fi;
        cin >> si >> fi;

        double d = fi - si;
        double ans = 0;

        if (d <= 0) ans = 0;
        else {
            ans = d / (2 * M_PI * r / v);
            while (ans * v <= d) {
                ans += d / (2 * M_PI * r / v);
            }
        }

        cout << fixed << ans << endl;
    }

    return 0;
}
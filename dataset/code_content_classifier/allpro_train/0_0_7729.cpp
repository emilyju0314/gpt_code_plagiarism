#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        double prob = 1.0;
        double sorted_prob = 1.0;

        for (int i = 0; i < m; i++) {
            int r;
            double p;
            cin >> r >> p;

            if (a[r-1] == r) {
                prob *= (1.0 - p);
            } else {
                sorted_prob *= p;
            }
        }

        cout << fixed << setprecision(6) << 1 - prob << endl;
    }

    return 0;
}
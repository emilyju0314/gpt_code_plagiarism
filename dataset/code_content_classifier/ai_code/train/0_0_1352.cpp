#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> x(n), y(n), z(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());

        cout << x[n/2] << " " << y[n/2] << " " << z[n/2] << "\n";
    }

    return 0;
}
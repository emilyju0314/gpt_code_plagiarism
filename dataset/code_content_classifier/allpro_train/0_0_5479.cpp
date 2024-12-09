#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> x_minus(n), x_plus(n), y_minus(n - 1), y_plus(n - 1), z_minus(n - 2), z_plus(n - 2);

        for(int i = 0; i < n; i++) {
            cin >> x_minus[i] >> x_plus[i];
        }

        for(int i = 0; i < n - 1; i++) {
            cin >> y_minus[i] >> y_plus[i];
        }

        for(int i = 0; i < n - 2; i++) {
            cin >> z_minus[i] >> z_plus[i];
        }

        bool possible = true;
        long long lower = x_minus[0], upper = x_plus[0];
        for(int i = 1; i < n; i++) {
            lower = max(lower - y_plus[i - 1], x_minus[i]);
            upper = min(upper + y_plus[i - 1], x_plus[i]);
            if (lower > upper) {
                possible = false;
                break;
            }
        }

        for(int i = 2; i < n; i++) {
            long long min_diff = (z_minus[i - 2] - y_plus[i - 1]);
            long long max_diff = (z_plus[i - 2] - y_minus[i - 1]);
            if (min_diff > (x_plus[i] - x_minus[i]) || max_diff < (x_plus[i] - x_minus[i])) {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        int min_grain_weight = n * (a - b);
        int max_grain_weight = n * (a + b);
        int min_package_weight = c - d;
        int max_package_weight = c + d;

        if(max_grain_weight >= min_package_weight && min_grain_weight <= max_package_weight) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
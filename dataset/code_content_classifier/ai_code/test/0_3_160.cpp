#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, r_b, c_b, r_d, c_d;
        cin >> n >> m >> r_b >> c_b >> r_d >> c_d;

        int seconds = 0;
        
        while (r_b != r_d || c_b != c_d) {
            if (r_b < r_d) {
                r_b++;
            } else if (r_b > r_d) {
                r_b--;
            }

            if (c_b < c_d) {
                c_b++;
            } else if (c_b > c_d) {
                c_b--;
            }

            seconds++;
        }

        cout << seconds << endl;
    }

    return 0;
}
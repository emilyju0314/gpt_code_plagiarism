#include <iostream>
#include <cmath>

using namespace std;

int cleanTime(int n, int m, int r_b, int c_b, int r_d, int c_d) {
    int time = 0;
    int dr = 1, dc = 1;

    while (r_b != r_d || c_b != c_d) {
        if (r_b < r_d) {
            r_b += dr;
        } else if (r_b > r_d) {
            r_b -= dr;
        }

        if (c_b < c_d) {
            c_b += dc;
        } else if (c_b > c_d) {
            c_b -= dc;
        }

        dr *= -1;
        dc *= -1;

        time++;
    }

    return time;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, r_b, c_b, r_d, c_d;
        cin >> n >> m >> r_b >> c_b >> r_d >> c_d;

        int time = cleanTime(n, m, r_b, c_b, r_d, c_d);
        cout << time << endl;
    }

    return 0;
}
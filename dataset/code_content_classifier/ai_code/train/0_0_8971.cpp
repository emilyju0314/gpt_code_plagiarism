#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;

        int total_submissions = 1e9;
        if (p == 0) {
            total_submissions = 0;
        } else if (p == q) {
            if (x == y) {
                total_submissions = 0;
            }
        } else {
            int g = gcd(p, q);
            int num_submissions_q = q / g - 1;
            int num_submissions_p = p / g;
            int l = max((x + num_submissions_p - 1) / num_submissions_p, (y + num_submissions_q) / num_submissions_q);
            if (num_submissions_p * l - x < num_submissions_q * l - y) {
                total_submissions = num_submissions_q * l;
            } else {
                total_submissions = num_submissions_p * l;
            }
        }

        if (total_submissions > y - x) {
            cout << -1 << endl;
        } else {
            cout << total_submissions << endl;
        }
    }

    return 0;
}
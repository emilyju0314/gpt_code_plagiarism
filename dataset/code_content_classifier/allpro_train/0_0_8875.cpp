#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    double total_money = 0.0;

    for (int i = 0; i < n; i++) {
        if (is_prime(p)) {
            total_money += (r[i] / p - (l[i] - 1) / p) * 1000.0;
        }
    }

    cout << fixed;
    cout.precision(1);
    cout << total_money << endl;

    return 0;
}
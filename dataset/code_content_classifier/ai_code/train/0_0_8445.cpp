#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long l, r, k;
    cin >> l >> r >> k;

    vector<long long> powers;
    long long power = 1;
    while (power <= r) {
        if (power >= l) {
            powers.push_back(power);
        }
        if (__builtin_mul_overflow(power, k, &power)) {
            break;
        }
    }

    if (powers.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < powers.size(); i++) {
            cout << powers[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
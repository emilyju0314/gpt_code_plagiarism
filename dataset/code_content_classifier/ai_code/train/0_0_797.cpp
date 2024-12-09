#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int xor_sum = 0;
        bool has_odd = false;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            xor_sum ^= a;
            if (a % 2 != 0) {
                has_odd = true;
            }
        }

        if (has_odd && xor_sum == 0) {
            cout << "LOSE" << endl;
        } else if (has_odd || xor_sum != 0) {
            cout << "WIN" << endl;
        } else {
            cout << "DRAW" << endl;
        }
    }

    return 0;
}
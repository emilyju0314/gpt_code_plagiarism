#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;

    int count = 0;

    for (int i = 0; pow(2, i) <= r; i++) {
        for (int j = 0; pow(2, i) * pow(3, j) <= r; j++) {
            long long num = pow(2, i) * pow(3, j);
            if (num >= l && num <= r) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
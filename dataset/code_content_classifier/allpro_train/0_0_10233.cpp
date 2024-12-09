#include <iostream>
using namespace std;

int main() {
    int d_a, d_b;
    cin >> d_a >> d_b;

    if (d_a == 9 && d_b == 9) {
        cout << "89 90" << endl;
    } else if (d_a == d_b) {
        cout << d_a << "1 " << d_a << "2" << endl;
    } else if (d_a < d_b) {
        cout << d_a << d_b << " " << d_a << d_b + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
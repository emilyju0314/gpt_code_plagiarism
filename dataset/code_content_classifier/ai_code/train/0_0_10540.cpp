#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int l, r, x, y;
    cin >> l >> r >> x >> y;

    int count = 0;
    for (int a = l; a <= r; a++) {
        for (int b = l; b <= r; b++) {
            if (gcd(a, b) == x && lcm(a, b) == y) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int dx = abs(C - A);
    int dy = abs(D - B);

    int result = 0;
    if (dx == 0) {
        result = dy;
    } else if (dy == 0) {
        result = dx;
    } else {
        result = dx + dy - gcd(dx, dy);
    }

    cout << result << endl;

    return 0;
}
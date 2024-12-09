#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int l_a, r_a, t_a, l_b, r_b, t_b;
    cin >> l_a >> r_a >> t_a;
    cin >> l_b >> r_b >> t_b;

    int period_a = (r_a - l_a + 1) * t_a / gcd(t_a, r_a - l_a + 1);
    int period_b = (r_b - l_b + 1) * t_b / gcd(t_b, r_b - l_b + 1);

    int start = max(l_a, l_b);
    int end = min(l_a + period_a - 1, l_b + period_b - 1);

    if (start > end) {
        cout << 0 << endl;
    } else {
        cout << end - start + 1 << endl;
    }

    return 0;
}
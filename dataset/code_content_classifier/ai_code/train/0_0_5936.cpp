#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int maxn, maxa, q;
    cin >> maxn >> maxa >> q;

    long long count = 0;
    for (int i = 1; i <= maxn; i++) {
        for (int j = i+1; j <= maxn; j++) {
            int g = gcd(i, j);
            // First wrong solution: calculates x as x = an / g
            int x1 = j / g;
            // Second wrong solution: calculates x as x = an - n
            int x2 = j - i;
            if (x1 % 2 != x2 % 2) {
                count++;
            }
        }
    }

    cout << count % q;

    return 0;
}
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int findOptimalB(int a) {
    int ans = 1;
    while ((ans << 1) <= a) {
        ans <<= 1;
    }
    return ans;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;

        int b = findOptimalB(a);
        int xorVal = a ^ b;
        int andVal = a & b;

        cout << gcd(xorVal, andVal) << endl;
    }

    return 0;
}
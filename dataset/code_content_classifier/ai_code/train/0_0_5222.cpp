#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n + 1);
    vector<int> B(m + 1);

    for (int i = 0; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= m; i++) {
        cin >> B[i];
    }

    if (n == m) {
        if (A[n] * B[m] > 0) {
            int numerator = A[n] / abs(A[n]);
            int denominator = B[m] / abs(B[m]);
            int gcd_val = gcd(abs(A[n]), abs(B[m]));
            cout << numerator / gcd_val << "/" << denominator / gcd_val << endl;
        } else {
            cout << "0/1" << endl;
        }
    } else if (n > m) {
        if (A[n] * B[m] > 0) {
            cout << "Infinity" << endl;
        } else {
            cout << "-Infinity" << endl;
        }
    } else {
        cout << "0/1" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int modular_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;
        
        // m is remainder now, process same as Euclid's algo
        m = a % m, a = t;

        t = x0;
        
        x0 = x1 - q * x0;
        
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    int missing = 0, present = 0;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        if (sequence[i] == -1)
            missing++;
        else
            present++;
    }

    int total_inversions = (1LL * n * (n-1) / 2 - present) % MOD;
    int denominator = 1;

    for (int i = 1; i <= missing; i++) {
        denominator = 1LL * denominator * (missing + present - i) % MOD;
    }

    int inversed_denominator = modular_inverse(denominator, MOD);

    int expected_inversions = 1LL * total_inversions * inversed_denominator % MOD;

    cout << expected_inversions << endl;

    return 0;
}
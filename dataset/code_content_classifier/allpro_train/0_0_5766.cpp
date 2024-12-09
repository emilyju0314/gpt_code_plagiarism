#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n1, n2, n3, m1, m2, m3, s1, s2, s3;
        cin >> n1 >> n2 >> n3 >> m1 >> m2 >> m3 >> s1 >> s2 >> s3;

        long long n = n1 * n2 * n3;
        long long m = m1 * m2 * m3;
        long long s = s1 * s2 * s3;

        long long gcd = __gcd(n, m);

        long long result = 2 * gcd / s;

        cout << result << endl;
    }

    return 0;
}
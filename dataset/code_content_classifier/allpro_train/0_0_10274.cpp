#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n1, n2, n3;
        int m1, m2, m3;
        int s1, s2, s3;

        cin >> n1 >> n2 >> n3;
        cin >> m1 >> m2 >> m3;
        cin >> s1 >> s2 >> s3;

        int n = n1 * n2 * n3;
        int m = m1 * m2 * m3;
        int s = s1 * s2 * s3;

        vector<int> divisors;
        for (int d = 1; d * d <= s; d++) {
            if (s % d == 0) {
                divisors.push_back(d);
                if (d * d != s) {
                    divisors.push_back(s / d);
                }
            }
        }

        int count = 0;
        for (int a : divisors) {
            for (int b : divisors) {
                if (a + m1 + m2 == s / a && b + n1 + n2 == s / b) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
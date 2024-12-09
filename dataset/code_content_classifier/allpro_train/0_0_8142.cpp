#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    long long X, Y;
    cin >> n >> X >> Y;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (gcd(X, a[i]) == X) {
            for (int j = 0; j < n; j++) {
                if (lcm(a[i], a[j]) == Y) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
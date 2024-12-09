#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        long long result = gcd(a[0] + b[i], a[1] + b[i]);
        for (int j = 2; j < n; j++) {
            result = gcd(result, a[j] + b[i]);
        }
        cout << result << " ";
    }

    return 0;
}
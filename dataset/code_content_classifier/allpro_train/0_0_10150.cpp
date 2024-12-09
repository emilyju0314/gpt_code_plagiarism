#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    long long operations = 0;
    for (int i = 0; i < n; i++) {
        operations += abs(a[i] - g);
    }

    cout << operations << endl;

    return 0;
}
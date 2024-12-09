#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result += (long long) gcd(a[i], a[j]) * gcd(i + 1, j + 1);
            result %= MOD;
        }
    }

    cout << result << endl;

    return 0;
}
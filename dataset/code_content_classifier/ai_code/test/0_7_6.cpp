#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long prettiness = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prettiness = (prettiness + (gcd(a[i], a[j]) * gcd(i + 1, j + 1)) % MOD) % MOD;
        }
    }

    cout << prettiness << endl;

    return 0;
}
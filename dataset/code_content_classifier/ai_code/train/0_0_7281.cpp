#include <iostream>
#include <vector>
using namespace std;

long long ModAdd(long long a, long long b, long long p) {
    return (a % p + b % p) % p;
}

long long Sum(vector<long long>& a, int l, int r, long long p) {
    long long sum = 0;
    for (int i = l-1; i < r; i++) {
        sum = ModAdd(sum, a[i], p);
    }
    return sum;
}

int main() {
    int n, m;
    long long p;
    cin >> n >> m >> p;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << Sum(a, l, r, p) << endl;
    }

    return 0;
}
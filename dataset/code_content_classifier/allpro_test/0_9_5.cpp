#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            cnt++;
        }
    }

    long long ans = 0;
    long long totalPossibilities = power(k, cnt);
    long long allEqual = 1;
    long long notAllEqual = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            notAllEqual = (notAllEqual + allEqual) % MOD;
        } else {
            allEqual = (allEqual * (k - 1)) % MOD;
        }
    }

    ans = (allEqual * power(notAllEqual, MOD - 2)) % MOD;
    ans = (ans * totalPossibilities) % MOD;

    cout << ans << endl;

    return 0;
}
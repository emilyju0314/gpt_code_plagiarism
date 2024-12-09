#include <iostream>
using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;

    long long ans = 0;
    for (int m = 1; m <= n; ++m) {
        if (((m + 1) & (n + 1)) == t) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
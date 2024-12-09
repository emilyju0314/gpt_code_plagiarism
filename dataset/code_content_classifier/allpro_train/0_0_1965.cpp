#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    for (long long i = 1; i <= n; i *= 2) {
        ans += i;
    }

    cout << ans << endl;

    return 0;
}
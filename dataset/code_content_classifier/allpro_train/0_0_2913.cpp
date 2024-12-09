#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n, k, A, B;
    cin >> n >> k >> A >> B;

    long long ans = 0;

    while(n > 1) {
        if(n < k || (n % k != 0)) {
            ans += (n - 1) * A;
            n = 1;
        } else {
            long long cost = min((n / k) * B, (n - n / k) * A);
            ans += cost;
            n /= k;
        }
    }

    cout << ans << endl;

    return 0;
}
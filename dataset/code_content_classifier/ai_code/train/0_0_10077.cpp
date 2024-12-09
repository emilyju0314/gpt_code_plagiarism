#include <iostream>

using namespace std;

int main() {
    long long a, b, k;
    cin >> a >> b >> k;

    long long ans = 0;
    while(a > b) {
        if(a % k == 0) {
            long long steps = (a - max(a/k, b))/k;
            a = max(a/k, b);
            ans += steps;
        } else {
            ans += (a % k);
            a -= (a % k);
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}
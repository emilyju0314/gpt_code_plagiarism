#include <iostream>

using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;

    long long ans = 0;
    for (long long i = 62; i >= 0; i--) {
        if ((r & (1LL << i)) && !(l & (1LL << i))) {
            ans |= (1LL << i);
        } else if ((l & (1LL << i)) && !(r & (1LL << i))) {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
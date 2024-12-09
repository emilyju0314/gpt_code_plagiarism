#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long ans = 0;
    long long cur = 1;

    while (cur < n) {
        ans++;
        cur = (cur * 2) + 1;
    }

    cout << ans << endl;

    return 0;
}
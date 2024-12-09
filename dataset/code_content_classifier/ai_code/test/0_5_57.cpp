#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long s, n, k;
        cin >> s >> n >> k;

        if (k * (n - 1) < s && s <= k * n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
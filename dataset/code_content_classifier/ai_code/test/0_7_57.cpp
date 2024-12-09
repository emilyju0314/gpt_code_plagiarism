#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long s, n, k;
        cin >> s >> n >> k;

        if (s % n == k % n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
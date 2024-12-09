#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long s, n, k;
        cin >> s >> n >> k;

        // Check if n divides s evenly or k divides s evenly
        if (s % n == 0 || s % k == 0 || s % (n+k) == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
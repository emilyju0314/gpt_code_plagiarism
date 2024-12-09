#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long s, n, k;
        cin >> s >> n >> k;

        if (s / n * n >= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
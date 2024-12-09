#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b_prime(n - 1);
    vector<int> c_prime(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> b_prime[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> c_prime[i];
    }

    vector<int> a(n);

    a[0] = max(b_prime[0], c_prime[0]);

    for (int i = 1; i < n - 1; i++) {
        a[i] = max(b_prime[i], c_prime[i]);
        if (a[i] == a[i - 1]) {
            a[i] = min(b_prime[i], c_prime[i]);
        }
    }

    a[n - 1] = max(b_prime[n - 2], c_prime[n - 2]);

    bool possible = true;
    for (int i = 0; i < n - 1; i++) {
        if (max(a[i], a[i + 1]) != c_prime[i] || min(a[i], a[i + 1]) != b_prime[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
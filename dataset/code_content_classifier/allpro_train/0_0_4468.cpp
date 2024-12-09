#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int moves = 0;
    for (int i = 0; i < n - 1; i++) {
        if (__gcd(a[i], a[i + 1]) == 1) {
            if (a[i] % 2 == 0 || a[i + 1] % 2 == 0) {
                moves++;
            } else {
                moves += 2;
            }
        }
    }

    if (moves == 0) {
        cout << "YES\n0" << endl;
    } else {
        cout << "YES\n" << moves << endl;
    }

    return 0;
}
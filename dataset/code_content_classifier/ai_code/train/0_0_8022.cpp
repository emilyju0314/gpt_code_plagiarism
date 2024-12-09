#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int moves = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != 1) {
            bool found = false;

            for (int j = i + 1; j < n; j++) {
                if (gcd(a[i], a[j]) == 1) {
                    moves += (j - i);
                    i = j;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << moves << endl;

    return 0;
}
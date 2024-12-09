#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> operations;
        vector<int> b;

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = i + 1; j < 2 * n; j++) {
                if ((a[i] + a[j]) % 2 == 0) {
                    operations.push_back({i + 1, j + 1});
                    b.push_back(a[i] + a[j]);
                    break;
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            cout << operations[i].first << " " << operations[i].second << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, u, r;
    cin >> n >> u >> r;

    vector<int> a(n), b(n), k(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long max_points = 0;
    for (int i = 0; i < (1 << u); i++) {
        vector<int> temp_a = a;
        for (int j = 0; j < u; j++) {
            if (i & (1 << j)) {
                for (int t = 0; t < n; t++) {
                    temp_a[t] ^= k[t];
                }
            }
            else {
                for (int t = 0; t < n; t++) {
                    temp_a[t] += p[t];
                }
            }
        }

        int points = 0;
        for (int j = 0; j < n; j++) {
            points += b[j] == temp_a[j] + r;
        }

        max_points = max(max_points, (long long)points);
    }

    cout << max_points * (long long)n << endl;

    return 0;
}
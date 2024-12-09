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

    for (int mask = 0; mask < (1<<n); mask++) {
        vector<int> curr_a = a;

        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) {
                curr_a[p[i]-1] += r;
            }
        }

        for (int i = 0; i < n; i++) {
            curr_a[i] += u * k[i];
        }

        sort(curr_a.begin(), curr_a.end());
        sort(b.begin(), b.end());

        long long points = 0;
        for (int i = 0; i < n; i++) {
            points += abs(curr_a[i] - b[i]);
        }

        max_points = max(max_points, points);
    }

    cout << max_points << endl;

    return 0;
}
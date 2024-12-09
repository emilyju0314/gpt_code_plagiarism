#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t >> k;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int ans = 0;
    for (int i = 0; i < t; i++) {
        vector<int> new_people(n, 0);
        vector<int> passengers(k, 0);

        for (int j = 0; j < n; j++) {
            if (j > 0) {
                passengers.insert(passengers.begin(), new_people[j-1]);
            }

            int take = min(a[j], passengers.size());
            for (int p = 0; p < take; p++) {
                passengers[p] += min(a[j], k);
            }

            new_people[j] = b[j];
            for (int p = 0; p < k; p++) {
                new_people[j] -= min(new_people[j], k - passengers[p]);
            }

            if (new_people[j] > c[j]) {
                ans += new_people[j] - c[j];
                new_people[j] = c[j];
            }

            for (int p = 0; p < k; p++) {
                a[j] = max(0, a[j] - passengers[p]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
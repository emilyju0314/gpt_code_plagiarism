#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long h;
        cin >> n >> h;

        vector<int> attacks(n);
        for (int j = 0; j < n; j++) {
            cin >> attacks[j];
        }

        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            vector<int> damage(n);
            for (int j = 0; j < n; j++) {
                if (attacks[j] <= mid) {
                    damage[j] = 1;
                    if (j > 0) {
                        damage[j-1] -= 1;
                    }
                    if (j + h <= n) {
                        damage[j+h] += 1;
                    }
                }
            }

            long long total_damage = 0, current_damage = 0;
            for (int j = 0; j < n; j++) {
                current_damage += damage[j];
                total_damage += current_damage;
            }

            if (total_damage >= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << endl;
    }

    return 0;
}
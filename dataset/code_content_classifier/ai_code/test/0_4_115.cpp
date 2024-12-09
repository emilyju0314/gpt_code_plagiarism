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

        long long low = 1, high = 1e9;
        while (low < high) {
            long long mid = (low + high) / 2;
            vector<long long> damageTime;
            for (int j = 0; j < n; j++) {
                if (attacks[j] <= mid) {
                    damageTime.push_back(attacks[j]);
                } else {
                    damageTime.push_back(attacks[j] - mid);
                }
            }

            long long total_damage = 0;
            for (int j = 0; j < n; j++) {
                total_damage += (damageTime[j] - (j > 0 ? damageTime[j-1] : 0));
            }

            if (total_damage >= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << endl;
    }

    return 0;
}
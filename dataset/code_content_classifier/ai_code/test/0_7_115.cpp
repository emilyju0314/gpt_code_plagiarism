#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long h;
        cin >> n >> h;

        vector<int> attacks(n);
        for (int i = 0; i < n; i++) {
            cin >> attacks[i];
        }

        int left = 1, right = 1000000000;
        while (left < right) {
            int mid = (left + right) / 2;
            vector<int> duration(mid + 1, 0);
            for (int i = 1; i <= mid; i++) {
                duration[i] = duration[i - 1] + 1;
            }
            for (int i = 0; i < n; i++) {
                duration[attacks[i]]--;
            }
            long long total_damage = 0;
            for (int i = 1; i <= mid; i++) {
                total_damage += duration[i];
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
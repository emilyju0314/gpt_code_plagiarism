#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        long long h;
        cin >> n >> h;

        vector<int> attacks(n);
        for(int i = 0; i < n; i++) {
            cin >> attacks[i];
        }

        int left = 1, right = attacks[n-1], ans = right;
        while(left <= right) {
            int mid = (left + right) / 2;
            vector<int> damage(n, 0);

            for(int i = 0; i < n; i++) {
                if(attacks[i] <= mid) {
                    for(int j = attacks[i]; j <= min(attacks[i] + mid - 1, attacks[n-1]); j++) {
                        damage[j-1]++;
                    }
                }
            }

            long long total_damage = 0;
            for(int i = 0; i < mid; i++) {
                total_damage += damage[i];
            }

            if(total_damage >= h) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
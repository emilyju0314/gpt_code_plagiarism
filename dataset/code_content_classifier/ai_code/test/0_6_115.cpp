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

        int left = 1, right = attacks[n-1];
        int result = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            vector<int> damage(2*mid + 1, 0);
            for (int i = 0; i < n; i++) {
                damage[max(0, attacks[i]-mid)]++;
                damage[attacks[i]+mid+1]--;
            }

            for (int i = 1; i < 2*mid + 1; i++) {
                damage[i] += damage[i-1];
            }

            long long total_damage = 0;
            for (int i = 0; i < 2*mid + 1; i++) {
                if (i >= mid) {
                    total_damage += damage[i];
                }
            }

            if (total_damage >= h) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
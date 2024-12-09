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
        
        long long left = 1, right = 1e18;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            vector<long long> damage(mid + 1, 0);
            for (int i = 0; i < n; i++) {
                damage[attacks[i]]++;
                damage[min(attacks[i] + mid, (long long) damage.size() - 1)]--;
            }
            for (int i = 1; i < damage.size(); i++) {
                damage[i] += damage[i - 1];
            }
            long long total_damage = 0;
            for (int i = 0; i < mid; i++) {
                total_damage += damage[i];
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
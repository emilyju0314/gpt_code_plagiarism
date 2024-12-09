#include <iostream>
#include <vector>
#include <algorithm>

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

        sort(attacks.begin(), attacks.end());

        int low = 1, high = attacks[n-1], result = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            long long total_damage = 0;
            for(int i = 0; i < n; i++) {
                total_damage += (attacks[i] / mid);
                total_damage += (attacks[i] % mid != 0 ? 1 : 0);
            }

            if(total_damage >= h) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
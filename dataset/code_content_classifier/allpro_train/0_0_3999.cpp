#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ans = 0;
        k = min(k, m-1);

        for(int i = 0; i <= k; i++) {
            int min_val = 1e9;
            for(int j = 0; j <= m-k-1; j++) {
                min_val = min(min_val, max(arr[i+j], arr[i+j+n-m]));
            }
            ans = max(ans, min_val);
        }

        cout << ans << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        int ans = 0;
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (int j = i; j < n; j += k) {
                if (sum + a[j] <= p) {
                    sum += a[j];
                    ans = max(ans, j + 1);
                }
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
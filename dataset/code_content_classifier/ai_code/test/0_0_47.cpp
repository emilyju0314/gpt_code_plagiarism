#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> x(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        long long ans = 0;
        for(int i = n-1; i >= 0; i -= k) {
            ans += 2*(x[i]);
        }

        cout << ans << endl;
    }

    return 0;
}
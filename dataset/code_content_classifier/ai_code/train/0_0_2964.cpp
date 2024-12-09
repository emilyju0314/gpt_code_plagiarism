#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> a(2*n, 0);
        for(int i = 0; i < n; i++) {
            a[b[i]-1] = 1;
        }

        vector<int> cnt(n+1, 0);
        for(int i = 0; i < 2*n; i++) {
            cnt[a[i]]++;
        }

        int curr = 0, ans = n;
        for(int i = 1; i <= n; i++) {
            curr += cnt[i] % 2;
            ans = min(ans, curr + n - i);
        }

        cout << ans << endl;
    }

    return 0;
}
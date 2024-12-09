#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for(int med = 1; med <= n; med++) {
        int cnt = 0;
        vector<int> zeros(n+1);
        for(int i = 0; i < n; i++) {
            if(a[i] >= med) {
                zeros[i+1] = zeros[i] + 1;
            } else {
                zeros[i+1] = zeros[i] - 1;
            }
        }

        for(int i = k; i <= n; i++) {
            cnt = max(cnt, zeros[i] - zeros[i-k]);
        }

        if(cnt > 0) {
            ans = max(ans, med);
        }
    }

    cout << ans << endl;

    return 0;
}
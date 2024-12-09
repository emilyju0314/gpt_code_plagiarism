#include <iostream>
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
        vector<int> y(n);

        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int mx = 0;

        for(int i = 0; i <= n; i++) {
            int l = i, r = n - i;

            if(l > r) {
                break;
            }

            int cnt = min(l, r) + min(l + (r - l) / 2, r - (r - l) / 2);
            mx = max(mx, cnt);
        }

        cout << mx << endl;
    }

    return 0;
}
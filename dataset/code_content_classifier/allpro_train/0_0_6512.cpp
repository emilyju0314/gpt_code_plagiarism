#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while(q--) {
        int x, y;
        cin >> x >> y;

        vector<int> prefix(n+1, 0);
        for(int i = 0; i < x; i++) {
            prefix[a[i]]++;
        }

        int ans = 0, maxVal = 0;

        for(int i = 1; i <= n; i++) {
            prefix[i] += prefix[i-1];
        }

        for(int i = 0; i < n-y; i++) {
            maxVal = max(maxVal, a[i]);
            if(prefix[maxVal] >= maxVal - i) {
                ans = max(ans, maxVal - i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
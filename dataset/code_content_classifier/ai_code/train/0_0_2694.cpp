#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        int cnt[3] = {0, 0, 0};
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i] % 3]++;
        }
        
        int ans = cnt[0];
        int mn = min(cnt[1], cnt[2]);
        
        ans += mn;
        cnt[1] -= mn;
        cnt[2] -= mn;
        
        ans += cnt[1] / 3 + cnt[2] / 3;
        
        cout << ans << endl;
    }
    
    return 0;
}
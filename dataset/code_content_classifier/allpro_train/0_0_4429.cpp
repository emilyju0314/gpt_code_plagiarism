#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    while(q--) {
        int n;
        cin >> n;
        
        vector<long long> prices(n);
        for(int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        
        sort(prices.begin(), prices.end(), greater<int>());
        
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        
        long long k;
        cin >> k;
        
        long long low = 0, high = n, ans = -1;
        while(low <= high) {
            long long mid = (low + high) / 2;
            vector<long long> contributions(n + 1);
            for(int i = 1; i <= mid; i++) {
                contributions[i] = contributions[i - 1] + prices[i - 1] / 100 * (x + y);
            }
            
            for(int i = 1; i <= mid; i++) {
                if(i % a == 0) {
                    contributions[i] -= prices[i - 1] / 100 * (x + y - x);
                }
                if(i % b == 0) {
                    contributions[i] -= prices[i - 1] / 100 * (x + y - y);
                }
            }
            
            if(contributions[mid] >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
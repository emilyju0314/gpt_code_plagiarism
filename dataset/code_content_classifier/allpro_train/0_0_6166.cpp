#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        cin >> cnt[i];
    }
    
    for(int i = 0; i < q; i++) {
        int type, x, k;
        cin >> type >> x >> k;
        
        if(type == 1) {
            cnt[x] = k;
        } else {
            long long totalOps = 0;
            for(int j = 0; j < n; j++) {
                totalOps += (long long)cnt[j] * (1ll << max(0, x - j));
            }
            
            if(totalOps < k) {
                cout << "-1\n";
            } else {
                int ops = 0;
                for(int j = n - 1; j >= 0; j--) {
                    int diff = min(k, cnt[j] * (1 << max(0, x - j)));
                    k -= diff;
                    ops += diff / (1 << max(0, x - j));
                }
                
                cout << ops << "\n";
            }
        }
    }
    
    return 0;
}
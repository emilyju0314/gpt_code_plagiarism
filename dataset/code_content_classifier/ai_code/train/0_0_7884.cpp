#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    
    if(k == 1) {
        map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        
        for(auto it : cnt) {
            ans += (long long)(it.second) * (it.second - 1) / 2;
        }
    } else {
        vector<vector<int>> cnt(1 << k, vector<int>(2, 0));
        vector<int> pref(n, 0), arr(n, 0);
        
        for(int i = 0; i < n; i++) {
            pref[i] = (i == 0 ? 0 : pref[i - 1]) ^ a[i];
        }
        
        int best = 0;
        
        for(int i = 0; i < n; i++) {
            arr[i] = pref[i];
            best = max(best, arr[i]);
            cnt[arr[i]][0] = -1;
        }
        
        for(int b = 0; b < (1 << k); b++) {
            for(int bb = 0; bb < (1 << k); bb++) {
                if(cnt[bb][0] == -1) continue;
                int ok = 1;
                
                for(int j = 0; j < k; j++) {
                    if((bb & (1 << j)) && (b & (1 << j))) {
                        ok = 0;
                        break;
                    }
                }
                
                if(ok) {
                    cnt[arr[bb]][1] += cnt[bb][0] + 1;
                }
            }
            
            for(int bb = 0; bb < (1 << k); bb++) {
                if(cnt[bb][0] == -1) continue;
                for(int j = 0; j < k; j++) {
                    if(!(b & (1 << j))) {
                        cnt[bb ^ (1 << j)][0] = max(cnt[bb ^ (1 << j)][0], cnt[bb][0]);
                    }
                }
            }
        }
        
        for(int b = 0; b < (1 << k); b++) {
            ans += cnt[b][1];
        }
        
        ans += (long long)n * (n + 1) / 2;
        ans -= (long long)best * (best + 1) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}
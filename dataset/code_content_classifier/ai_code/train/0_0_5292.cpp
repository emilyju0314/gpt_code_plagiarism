#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> slides(m);
    for(int i = 0; i < m; i++) {
        cin >> slides[i].first >> slides[i].second;
    }
    
    int ans = 0;
    for(int mask = 0; mask < (1 << m); mask++) {
        vector<int> height(n+1, 1);
        bool legal = true;
        for(int i = 0; i < m; i++) {
            if(mask & (1 << i)) {
                swap(slides[i].first, slides[i].second);
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(auto slide: slides) {
                if(height[slide.second] <= height[slide.first]) {
                    legal = false;
                    break;
                }
                height[slide.second] = max(height[slide.second], height[slide.first] + 1);
            }
        }
        
        if(legal) {
            ans++;
        }
    }
    
    cout << ans % MOD << endl;
    
    return 0;
}
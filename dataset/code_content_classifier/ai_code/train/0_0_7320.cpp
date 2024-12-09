#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> segments;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }
    
    sort(segments.begin(), segments.end());
    
    long long ans = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ans += max(0, min(segments[i].second, segments[j].second) - max(segments[i].first, segments[j].first) + 1);
            ans %= MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
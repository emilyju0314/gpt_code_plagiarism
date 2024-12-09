#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    map<int, vector<int>> indices;
    for(int i = 0; i < n; i++) {
        indices[sequence[i]].push_back(i);
    }
    
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        int min_dist = n+1;
        for(auto& it : indices) {
            vector<int>& idx = it.second;
            if(idx.size() < 2) continue;
            
            auto low = lower_bound(idx.begin(), idx.end(), l);
            auto high = upper_bound(idx.begin(), idx.end(), r);
            
            if(low != high) {
                min_dist = min(min_dist, *high - *low);
            }
        }
        
        if(min_dist == n+1) {
            cout << "-1" << endl;
        } else {
            cout << min_dist << endl;
        }
    }
    
    return 0;
}
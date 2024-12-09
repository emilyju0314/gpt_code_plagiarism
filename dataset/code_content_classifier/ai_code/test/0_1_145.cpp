#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        int maxX = -1e9, maxY = -1e9, minX = 1e9, minY = 1e9;
        
        vector<pair<pair<int, int>, int>> mines;
        
        for(int i = 0; i < n; i++) {
            int x, y, timer;
            cin >> x >> y >> timer;
            mines.push_back({{x, y}, timer});
            
            maxX = max(maxX, x);
            maxY = max(maxY, y);
            minX = min(minX, x);
            minY = min(minY, y);
        }
        
        int ans = 0;
        
        for(auto mine : mines) {
            int x = mine.first.first;
            int y = mine.first.second;
            int timer = mine.second;
            
            int distX = max(max(abs(x - maxX), abs(x - minX)), 0);
            int distY = max(max(abs(y - maxY), abs(y - minY)), 0);
            
            ans = max(ans, max(distX, distY) + timer + k);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
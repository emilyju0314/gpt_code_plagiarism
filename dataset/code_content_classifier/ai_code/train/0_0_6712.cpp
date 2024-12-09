#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int r, c, n, k;
    cin >> r >> c >> n >> k;
    
    vector<pair<int, int>> violas;
    set<pair<int, int>> viola_set;
    
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        violas.push_back({x, y});
        viola_set.insert({x, y});
    }
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int x1 = violas[i].first, y1 = violas[i].second;
            int x2 = violas[j].first, y2 = violas[j].second;
            
            int minX = min(x1, x2), maxX = max(x1, x2);
            int minY = min(y1, y2), maxY = max(y1, y2);
            
            int violas_in_rect = 0;
            for(auto v : viola_set) {
                if(v.first >= minX && v.first <= maxX && v.second >= minY && v.second <= maxY) {
                    violas_in_rect++;
                }
            }
            
            if(violas_in_rect >= k) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
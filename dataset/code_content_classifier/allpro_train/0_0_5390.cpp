#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> points;
        
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }
        
        sort(points.begin(), points.end());
        
        int min_x = points[0].first;
        int max_x = points[n-1].first;
        
        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        });
        
        int min_y = points[0].second;
        int max_y = points[n-1].second;
        
        int area1 = max_x - min_x;
        int area2 = max_y - min_y;
        
        if(area1 < 0) area1 = 0;
        if(area2 < 0) area2 = 0;
        
        cout << area1 * area2 << endl;
    }
    
    return 0;
}
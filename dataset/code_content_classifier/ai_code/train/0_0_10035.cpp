#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int w, h;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;
        
        int n;
        cin >> n;
        
        vector<pair<int, int>> points;
        
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            points.push_back({x1, y1});
            points.push_back({x2, y2});
        }
        
        sort(points.begin(), points.end());
        
        int colors = 0;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i].first;
            int y = points[i].second;
            
            while (i+1 < points.size() && points[i+1].first == x) {
                i++;
                y = max(y, points[i].second);
            }
            
            if (i+1 < points.size()) {
                int next_x = points[i+1].first;
                for (int j = i+1; j < points.size(); j++) {
                    if (points[j].second > y && points[j].first > next_x) {
                        colors++;
                        break;
                    }
                }
            }
        }
        
        cout << colors + 1 << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    
    while (true) {
        cin >> n >> r;
        
        if (n == 0 && r == 0) {
            break;
        }
        
        vector<pair<int, int>> start, end;
        
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            start.push_back({x1, y1});
            end.push_back({x2, y2});
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int area = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int dx = start[i + 1].first - end[i].first;
            int dy = min(end[i].second, end[i + 1].second) - max(start[i].second, start[i + 1].second);
            area += max(dx, 0) * max(dy, 0);
        }
        
        cout << area << endl;
        
        if (r == 2) {
            int perimeter = 0;
            
            for (int i = 0; i < n; i++) {
                int dx = end[i].first - start[i].first;
                int dy = end[i].second - start[i].second;
                perimeter += 2 * (dx + dy);
            }
            
            cout << perimeter << endl;
        }
    }
    
    return 0;
}
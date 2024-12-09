#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const double EPS = 1e-9;

double hdist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool possible(double v, vector<pair<int, pair<int, int>>> raindrops, int w, int h, int e1, int e2) {
    double left_end = e1, right_end = e2;
    
    for (auto it : raindrops) {
        int t = it.first;
        int x = it.second.first, y = it.second.second;
        
        double left_dist = hdist(left_end, 0, x, y);
        double right_dist = hdist(right_end, h, x, y);
        
        double max_dist = max(left_dist, right_dist);
        
        if (max_dist > v * t + EPS) {
            return false;
        }
        
        left_end = max(left_end, x - v * t);
        right_end = min(right_end, x + v * t);
    }
    
    return true;
}

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    
    int e1, e2;
    cin >> e1 >> e2;
    
    vector<pair<int, pair<int, int>>> raindrops;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        raindrops.push_back({t, {x, y}});
    }
    
    double low = 0, high = 1e18;
    
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;
        
        if (possible(mid, raindrops, w, h, e1, e2)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if (high > 1e17) {
        cout << "-1\n";
    } else {
        cout << fixed << high << endl;
    }
    
    return 0;
}
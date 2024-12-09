#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

bool arePolygonsSimilar(vector<Point>& polygon) {
    int n = polygon.size();
    
    long long min_x = LLONG_MAX, max_x = LLONG_MIN;
    long long min_y = LLONG_MAX, max_y = LLONG_MIN;
    
    for (int i = 0; i < n; i++) {
        min_x = min(min_x, polygon[i].x);
        max_x = max(max_x, polygon[i].x);
        min_y = min(min_y, polygon[i].y);
        max_y = max(max_y, polygon[i].y);
    }
    
    long long width = max_x - min_x;
    long long height = max_y - min_y;
    
    for (int i = 0; i < n; i++) {
        long long curr_width = polygon[(i + 1) % n].x - polygon[i].x;
        long long curr_height = polygon[(i + 1) % n].y - polygon[i].y;
        
        if ((curr_width != 0 && curr_height != 0) || 
            (curr_width == 0 && curr_height == 0) || 
            (width % curr_width != 0) || 
            (height % curr_height != 0)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    if (arePolygonsSimilar(polygon)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
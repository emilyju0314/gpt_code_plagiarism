#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double pointInShade(int sy, int a, int b, vector<pair<int, int>>& segments, int x, int y) {
    double shadeTime = 0;
    for(auto segment : segments) {
        if(segment.second <= y || segment.first >= y) continue;
        
        double x_intersect = (double)(segment.first - x) * (double)(b - a) / (double)(sy - y) + x;
        double y_intersect = y;
        
        if(x_intersect >= min(segment.first, segment.second) && x_intersect <= max(segment.first, segment.second)) {
            shadeTime += min((double)b, x_intersect) - max((double)a, x_intersect);
        }
    }
    
    return shadeTime;
}

int main() {
    int sy, a, b;
    cin >> sy >> a >> b;
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> segments(n);
    for(int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        double shadeTime = pointInShade(sy, a, b, segments, x, y);
        cout << fixed << shadeTime << endl;
    }
    
    return 0;
}
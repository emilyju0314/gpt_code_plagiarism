#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort(points.begin(), points.end());
    
    int leftMax = points[0].second, rightMin = points.back().second;
    long long ans = (long long)(rightMin - leftMax) * (rightMin - leftMax);
    
    for(int i = 1; i < n - 1; i++) {
        leftMax = max(leftMax, points[i].second);
        rightMin = min(rightMin, points[i].second);
        
        ans = min(ans, (long long)(points[i].first - points[0].first) * (points[n - 1].first - points[i + 1].first) + (long long)(rightMin - leftMax) * (rightMin - leftMax));
    }
    
    cout << ans << endl;
    
    return 0;
}
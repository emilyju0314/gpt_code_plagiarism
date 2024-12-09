#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    int max_x = 0, max_y = 0;
    for(int i = 0; i < n; i++) {
        max_x = max(max_x, points[i].first);
        max_y = max(max_y, points[i].second);
    }
    
    int min_side = max(max_x, max_y);
    cout << min_side * 2 << endl;
    
    return 0;
}
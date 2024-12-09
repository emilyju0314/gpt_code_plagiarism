#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int s_x, s_y, f_x, f_y;
    cin >> s_x >> s_y >> f_x >> f_y;
    
    vector<pair<int, int>> locations;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        locations.push_back({x, y});
    }
    
    int min_time = abs(s_x - f_x) + abs(s_y - f_y);
    for(auto loc : locations) {
        int x = loc.first;
        int y = loc.second;
        
        if ((x >= min(s_x, f_x) && x <= max(s_x, f_x)) || (y >= min(s_y, f_y) && y <= max(s_y, f_y))) {
            min_time = min(min_time, abs(s_x - x) + abs(s_y - y) + abs(f_x - x) + abs(f_y - y));
        }
    }
    
    cout << min_time << endl;
    
    return 0;
}
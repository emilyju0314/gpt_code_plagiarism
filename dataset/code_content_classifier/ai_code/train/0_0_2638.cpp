#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> mines;
    
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mines.push_back({x, y});
    }
    
    int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;
    
    for(auto mine : mines) {
        minX = min(minX, mine.first);
        maxX = max(maxX, mine.first);
        minY = min(minY, mine.second);
        maxY = max(maxY, mine.second);
    }
    
    int side = max(maxX - minX, maxY - minY);
    int area = side * side;
    
    cout << area << endl;
    
    return 0;
}
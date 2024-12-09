#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> houses;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            houses.push_back({x, y});
        }
        
        sort(houses.begin(), houses.end());
        
        vector<int> xValues, yValues;
        for(auto house: houses) {
            xValues.push_back(house.first);
            yValues.push_back(house.second);
        }
        
        sort(yValues.begin(), yValues.end());
        
        int medianX = xValues[n/2];
        int medianY = yValues[n/2];
        
        long long totalDist = 0;
        for(auto house: houses) {
            totalDist += (abs(house.first - medianX) + abs(house.second - medianY));
        }
        
        cout << 1 << endl;
    }
    
    return 0;
}
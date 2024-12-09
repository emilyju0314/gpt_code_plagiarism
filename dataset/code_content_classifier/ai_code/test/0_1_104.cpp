#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> dishes;
        
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            dishes.push_back({a, b});
        }
        
        sort(dishes.begin(), dishes.end());
        
        int totalFish = 0;
        int totalMeat = 0;
        for (auto dish : dishes) {
            totalFish += dish.first;
            totalMeat += dish.second;
        }
        
        int diff = abs(totalFish - totalMeat);
        cout << diff << endl;
        
        for (auto dish : dishes) {
            int x = min(m, dish.first);
            int y = m - x;
            cout << x << " " << y << endl;
        }
    }
    
    return 0;
}
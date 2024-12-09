#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<pair<int, int>, int>> dishes;
        int total_min_variety = 0;
        
        for(int i = 0; i < n; i++) {
            int a, b, m;
            cin >> a >> b >> m;
            
            dishes.push_back({{a, b}, m});
        }
        
        sort(dishes.begin(), dishes.end());
        
        for(int i = 0; i < n; i++) {
            int excess_fish = 0, excess_meat = 0;
            
            while(dishes[i].second > 0) {
                if(excess_fish >= excess_meat) {
                    int eaten_fish = min(dishes[i].first.first, dishes[i].second);
                    dishes[i].first.first -= eaten_fish;
                    dishes[i].second -= eaten_fish;
                    excess_fish += eaten_fish;
                } else {
                    int eaten_meat = min(dishes[i].first.second, dishes[i].second);
                    dishes[i].first.second -= eaten_meat;
                    dishes[i].second -= eaten_meat;
                    excess_meat += eaten_meat;
                }
            }
            
            cout << excess_fish + excess_meat << "\n";
            
            for(int j = 0; j < excess_fish; j++) {
                cout << "1 0\n";
            }
            for(int j = 0; j < excess_meat; j++) {
                cout << "0 1\n";
            }
        }
    }
    
    return 0;
}
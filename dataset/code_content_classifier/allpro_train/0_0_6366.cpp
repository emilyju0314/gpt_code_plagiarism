#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        vector<pair<int, int>> bots(4);
        for(int j = 0; j < 4; j++) {
            int x, y;
            cin >> x >> y;
            bots[j] = make_pair(x, y);
        }
        
        sort(bots.begin(), bots.end());
        
        if((bots[0].first == bots[1].first && bots[2].first == bots[3].first) && 
           (bots[0].second == bots[2].second && bots[1].second == bots[3].second) &&
           (bots[1].second - bots[0].second == bots[3].first - bots[0].first)) {
            int side = bots[1].second - bots[0].second;
            cout << "0\n";
            cout << bots[0].first << " " << bots[0].second << "\n";
            cout << bots[1].first << " " << bots[1].second << "\n";
            cout << bots[2].first << " " << bots[2].second << "\n";
            cout << bots[3].first << " " << bots[3].second << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}
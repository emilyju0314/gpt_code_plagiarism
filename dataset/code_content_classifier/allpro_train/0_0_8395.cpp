#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, hx, hy, dx, dy;
    
    while (cin >> n >> hx >> hy >> dx >> dy) {
        if (n == 0 && hx == 0 && hy == 0 && dx == 0 && dy == 0) {
            break;
        }

        vector<pair<int, int>> crystals;
        for (int i = 0; i < n; i++) {
            int cx, cy;
            cin >> cx >> cy;
            crystals.push_back(make_pair(cx, cy));
        }
        
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            double distance_to_hero = sqrt(pow(crystals[i].first - hx, 2) + pow(crystals[i].second - hy, 2));
            double distance_to_demon_king = sqrt(pow(crystals[i].first - dx, 2) + pow(crystals[i].second - dy, 2));
            
            if (distance_to_hero + distance_to_demon_king > 2 * sqrt(pow(dx - hx, 2) + pow(dy - hy, 2))) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
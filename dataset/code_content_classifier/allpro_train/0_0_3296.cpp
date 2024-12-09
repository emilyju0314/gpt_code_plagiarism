#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, int>> S;

int getSizeOfExtension() {
    set<pair<int, int>> R = S;
    
    bool found = true;
    while (found) {
        found = false;
        for (auto p1 : R) {
            for (auto p2 : R) {
                int x1 = p1.first, y1 = p1.second;
                int x2 = p2.first, y2 = p2.second;
                
                if (x1 != x2 && y1 != y2 && R.find({x1, y2}) != R.end() && R.find({x2, y1}) == R.end()) {
                    found = true;
                    R.insert({x2, y1});
                }
            }
        }
    }
    
    return R.size();
}

int main() {
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        
        if (S.count({x, y})) {
            S.erase({x, y});
        } else {
            S.insert({x, y});
        }
        
        cout << getSizeOfExtension() << " ";
    }
    
    return 0;
}
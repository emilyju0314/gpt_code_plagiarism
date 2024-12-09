#include <iostream>
#include <vector>

using namespace std;

bool canConstructSquare(int n, int m, vector<pair<pair<int, int>, pair<int, int>>> tiles) {
    for (int i=0; i<2*n; i+=2) {
        if (tiles[i].second != tiles[i+1].first) {
            return false;
        }
    }
    if (m%2 != 0) {
        return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<pair<pair<int, int>, pair<int, int>>> tiles(2*n);
        for (int i=0; i<2*n; i++) {
            cin >> tiles[i].first.first >> tiles[i].first.second;
            cin >> tiles[i].second.first >> tiles[i].second.second;
        }
        
        if (canConstructSquare(n, m, tiles)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
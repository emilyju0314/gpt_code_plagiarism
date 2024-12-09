#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> tiles;
    
    for (int i = 0; i < N; i++) {
        int xL1, xL2, xU1, xU2;
        cin >> xL1 >> xL2 >> xU1 >> xU2;
        tiles.push_back({xL1, xU1});
        tiles.push_back({xL2, xU2});
    }
    
    sort(tiles.begin(), tiles.end());
    
    int ans = 0;
    int end = tiles[0].second;
    
    for (int i = 1; i < tiles.size(); i++) {
        if (tiles[i].first > end) {
            ans++;
            end = tiles[i].second;
        } else {
            end = max(end, tiles[i].second);
        }
    }
    
    cout << ans + 1 << endl;
    
    return 0;
}
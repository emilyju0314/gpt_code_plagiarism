#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, int>> centers;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        centers.push_back({x, y});
    }
    
    int maxDist = 0;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            int xDiff = abs(centers[i].first - centers[j].first);
            int yDiff = abs(centers[i].second - centers[j].second);
            maxDist = max(maxDist, max(xDiff, yDiff));
        }
    }
    
    int ans = (maxDist + 1) / 2;
    cout << ans << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<pair<int, int>> streetlights(N);
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        streetlights[i] = make_pair(x, y);
    }

    int maxDist = 0;
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            int curDist = INT_MAX;
            for(auto light : streetlights) {
                curDist = min(curDist, abs(i - light.first) + abs(j - light.second));
            }
            maxDist = max(maxDist, curDist);
        }
    }

    cout << maxDist << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> campus(H, vector<char>(W));
    vector<pair<int, int>> buildings;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> campus[i][j];
            if(campus[i][j] == 'B') {
                buildings.push_back({i, j});
            }
        }
    }

    int max_distance = 0;
    for(auto& b1 : buildings) {
        for(auto& b2 : buildings) {
            int distance = abs(b1.first - b2.first) + abs(b1.second - b2.second);
            max_distance = max(max_distance, distance);
        }
    }

    cout << max_distance << endl;

    return 0;
}
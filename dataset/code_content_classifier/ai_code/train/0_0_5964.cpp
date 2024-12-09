#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int H, int W, int C, vector<vector<int>>& map, vector<pair<int, int>>& inhabited) {
    // find the minimum height among the inhabited cells
    int min_height = INT_MAX;
    for (auto cell : inhabited) {
        min_height = min(min_height, map[cell.first][cell.second]);
    }

    // check if it is possible to construct a dam with capacity equal to or more than C
    if (min_height >= C) {
        return true;
    }

    return false;
}

int main() {
    while (true) {
        int H, W, C, R;
        cin >> H >> W >> C >> R;

        if (H == 0 && W == 0 && C == 0 && R == 0) {
            break;
        }

        vector<vector<int>> map(H, vector<int>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }

        vector<pair<int, int>> inhabited;
        for (int i = 0; i < R; i++) {
            int y, x;
            cin >> y >> x;
            inhabited.push_back({y, x});
        }

        if (isPossible(H, W, C, map, inhabited)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
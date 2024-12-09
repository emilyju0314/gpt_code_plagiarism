#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W, H, T;
    cin >> W >> H >> T;

    int p;
    cin >> p;

    vector<vector<pair<int, int>>> fertilizing(p);
    for (int i = 0; i < p; i++) {
        int xi, yi, ti;
        cin >> xi >> yi >> ti;
        fertilizing[i] = { {xi, yi}, ti };
    }

    vector<vector<int>> field(W, vector<int>(H, 0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> field[j][i];
        }
    }

    for (int i = 0; i < p; i++) {
        int xi = fertilizing[i][0].first;
        int yi = fertilizing[i][0].second;
        int ti = fertilizing[i].second;
        
        if (ti <= T) {
            field[xi][yi]++;
        }
    }

    int total_height = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            total_height += field[j][i];
        }
    }

    cout << total_height << endl;

    return 0;
}
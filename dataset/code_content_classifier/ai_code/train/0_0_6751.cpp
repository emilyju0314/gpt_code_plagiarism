#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    vector<pair<int, int>> initial_positions(N);
    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        initial_positions[i] = {r, c};
    }

    vector<vector<pair<int, int>>> movements(N, vector<pair<int, int>>(H, {0, 0}));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H; j++) {
            int r, c;
            cin >> r >> c;
            movements[i][j] = {r, c};
        }
    }

    set<pair<int, int>> positions;
    for (int i = 0; i < H; i++) {
        positions.clear();
        for (int j = 0; j < N; j++) {
            pair<int, int> pos = initial_positions[j];
            while (true) {
                if (positions.count(pos) > 0) {
                    cout << i+1 << endl;
                    return 0;
                }
                positions.insert(pos);
                pos = movements[j][pos.first - 1];
                if (pos == make_pair(0, 0)) break;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> field(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> garlands(k);
    vector<bool> isTurnedOn(k, true);

    for (int garland = 0; garland < k; garland++) {
        int len;
        cin >> len;
        garlands[garland].resize(len);
        for (int bulb = 0; bulb < len; bulb++) {
            int i, j, w;
            cin >> i >> j >> w;
            garlands[garland][bulb] = {i, j, w};
            field[i-1][j-1] += w;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string event;
        cin >> event;
        if (event == "SWITCH") {
            int garlandIdx;
            cin >> garlandIdx;
            garlandIdx--;
            isTurnedOn[garlandIdx] = !isTurnedOn[garlandIdx];
            for (int bulb = 0; bulb < garlands[garlandIdx].size(); bulb++) {
                int i = garlands[garlandIdx][bulb].first;
                int j = garlands[garlandIdx][bulb].second;
                int w = garlands[garlandIdx][bulb].second;
                if (isTurnedOn[garlandIdx]) {
                    field[i-1][j-1] += w;
                } else {
                    field[i-1][j-1] -= w;
                }
            }
        } else if (event == "ASK") {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int sum = 0;
            for (int i = x1-1; i < x2; i++) {
                for (int j = y1-1; j < y2; j++) {
                    sum += field[i][j];
                }
            }
            cout << sum << "\n";
        }
    }

    return 0;
}
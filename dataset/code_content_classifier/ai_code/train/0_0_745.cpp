#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> creatures(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> creatures[i][j];
        }
    }

    vector<vector<int>> newCreatures;
    vector<int> queries;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 3) {
            queries.push_back(y);
        } else {
            newCreatures.push_back({x-1, y-1, t});
        }
    }

    for (auto& query : newCreatures) {
        if (query[2] == 1) {
            for (int j = 0; j < n; j++) {
                creatures.push_back({max(creatures[query[0]][j], creatures[query[1]][j])});
            }
            k++;
        } else {
            for (int j = 0; j < n; j++) {
                creatures.push_back({min(creatures[query[0]][j], creatures[query[1]][j])});
            }
            k++;
        }
    }

    for (int query : queries) {
        cout << creatures[query-1][0] << endl;
    }

    return 0;
}
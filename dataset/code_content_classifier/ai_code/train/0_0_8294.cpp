#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> subsets(N-1);
    vector<unordered_set<int>> neighbors(N+1);

    for (int i = 0; i < N-1; i++) {
        int c;
        cin >> c;
        subsets[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> subsets[i][j];
        }
    }

    for (int i = 0; i < N-1; i++) {
        neighbors[subsets[i][0]].insert(subsets[i][1]);
        neighbors[subsets[i][1]].insert(subsets[i][0]);
    }

    vector<pair<int, int>> edges;

    for (int i = 1; i <= N; i++) {
        if (neighbors[i].size() > 2) {
            cout << "-1" << endl;
            return 0;
        } else if (neighbors[i].size() == 1) {
            edges.push_back(make_pair(i, *neighbors[i].begin()));
        }
    }

    if (edges.size() == 0) {
        cout << "-1" << endl;
    } else {
        for (auto edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}
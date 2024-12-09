#include <iostream>
#include <vector>

using namespace std;

bool isomorphic(const vector<vector<int>>& treeA, const vector<vector<int>>& treeB, int nodeA, int nodeB) {
    if (treeA[nodeA].size() != treeB[nodeB].size()) {
        return false;
    }
    for (int i = 0; i < treeA[nodeA].size(); i++) {
        if (!isomorphic(treeA, treeB, treeA[nodeA][i], treeB[nodeB][i])) {
            return false;
        }
    }
    return true;
}

int min_operations(const vector<vector<int>>& treeA, const vector<vector<int>>& treeB, int nodeA, int nodeB) {
    if (treeA[nodeA].size() == 1) {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < treeA[nodeA].size(); i++) {
        int childA = treeA[nodeA][i];
        int childB = treeB[nodeB][i];
        ans += min_operations(treeA, treeB, childA, childB);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<vector<int>> treeA(N + 1), treeB(N + 1);

        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            treeA[a].push_back(b);
        }

        for (int i = 0; i < N - 1; i++) {
            int c, d;
            cin >> c >> d;
            treeB[c].push_back(d);
        }

        if (!isomorphic(treeA, treeB, 1, 1)) {
            cout << -1 << endl;
        } else {
            cout << min_operations(treeA, treeB, 1, 1) << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, v, e;
vector<int> ai, bi;
vector<vector<int>> tubes;
vector<int> result;

bool dfs(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            if (ai[i] != bi[i]) {
                return false;
            }
        }
        return true;
    }

    for (int i = 0; i < tubes.size(); i++) {
        int x = tubes[i][0], y = tubes[i][1];
        if (ai[x] > 0 && ai[y] < v) {
            int transfusion = min(ai[x], v - ai[y]);
            ai[x] -= transfusion;
            ai[y] += transfusion;
            result.push_back(x);
            result.push_back(y);
            result.push_back(transfusion);

            if (dfs(cur + 1)) {
                return true;
            }

            result.pop_back();
            result.pop_back();
            result.pop_back();
            ai[x] += transfusion;
            ai[y] -= transfusion;
        }
    }

    return false;
}

int main() {
    cin >> n >> v >> e;

    ai.resize(n);
    bi.resize(n);
    tubes.resize(e);

    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> bi[i];
    }

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        tubes[i] = {x - 1, y - 1};
    }

    if (dfs(0)) {
        cout << result.size() / 3 << endl;
        for (int i = 0; i < result.size(); i += 3) {
            cout << result[i] + 1 << " " << result[i + 1] + 1 << " " << result[i + 2] << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
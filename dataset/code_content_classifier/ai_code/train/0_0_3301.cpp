#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
long long k;
vector<vector<int>> priorities;
vector<vector<int>> priorities_sorted;
vector<int> positions;
vector<vector<string>> ans;

bool compare_arrays(const vector<string>& a, const vector<string>& b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                return priorities_sorted[i][j] < positions[i];
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m >> k;

    priorities.resize(n, vector<int>(m));
    priorities_sorted.resize(n, vector<int>(m));
    positions.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            cin >> priorities[i][j];
            positions[i] = max(positions[i], priorities[i][j]);
            priorities_sorted[i][j] = priorities[i][j];
        }
    }

    sort(positions.begin(), positions.end());

    ans.resize(n, vector<string>(m, ""));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = "(";
        }
    }

    long long cnt = 0;
    do {
        if (cnt == k-1) {
            for (const auto& row : ans) {
                for (const string& bracket : row) {
                    cout << bracket;
                }
                cout << endl;
            }
            break;
        }
        cnt++;
    } while (next_permutation(positions.begin(), positions.end()));

    return 0;
}
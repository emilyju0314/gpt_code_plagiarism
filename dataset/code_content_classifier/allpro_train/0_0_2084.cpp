#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidArrangement(const vector<int>& arrangement, const vector<pair<int, int>>& restrictions) {
    for (const auto& restriction : restrictions) {
        int senior = -1, junior = -1;
        for (int i = 0; i < arrangement.size(); i++) {
            if (arrangement[i] == restriction.first) {
                senior = i;
            }
            if (arrangement[i] == restriction.second) {
                junior = i;
            }
        }
        if (senior == -1 || junior == -1 || senior <= junior) {
            return false;
        }
    }
    return true;
}

void generateArrangements(vector<int>& arrangement, vector<vector<int>>& arrangements, vector<bool>& visited) {
    if (arrangement.size() == visited.size()) {
        arrangements.push_back(arrangement);
        return;
    }

    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            arrangement.push_back(i + 1);
            generateArrangements(arrangement, arrangements, visited);
            visited[i] = false;
            arrangement.pop_back();
        }
    }
}

int main() {
    int n, m;
    long long y;
    cin >> n >> y >> m;

    vector<pair<int, int>> restrictions;
    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        restrictions.push_back({ai, bi});
    }

    vector<vector<int>> arrangements;
    vector<int> arrangement;
    vector<bool> visited(n, false);
    generateArrangements(arrangement, arrangements, visited);

    sort(arrangements.begin(), arrangements.end());

    for (const auto& arr : arrangements) {
        if (isValidArrangement(arr, restrictions)) {
            if (y == 2001) {
                for (int professor : arr) {
                    cout << professor << " ";
                }
                cout << endl;
                return 0;
            }
            y--;
        }
    }

    cout << "The times have changed" << endl;

    return 0;
}
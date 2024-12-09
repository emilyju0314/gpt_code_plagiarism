#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> maintenance(n);
    for (int i = 0; i < n; i++) {
        cin >> maintenance[i];
    }

    vector<vector<int>> clients(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> clients[i][0] >> clients[i][1];
    }

    vector<set<int>> inaccessible(n);
    for (int i = 0; i < m; i++) {
        if (maintenance[clients[i][0] - 1] == maintenance[clients[i][1] - 1]) {
            inaccessible[clients[i][0] - 1].insert(i);
            inaccessible[clients[i][1] - 1].insert(i);
        }
    }

    int ans = n;
    vector<int> change;
    for (int i = 0; i < n; i++) {
        set<int> intersect;
        for (int client : inaccessible[i]) {
            if (inaccessible[i].find(client) != inaccessible[i].end()) {
                intersect.insert(client);
            }
        }
        if (intersect.size() < ans) {
            ans = intersect.size();
            change.clear();
            change.push_back(i + 1);
        } else if (intersect.size() == ans) {
            change.push_back(i + 1);
        }
    }

    cout << ans << endl;
    for (int data_center : change) {
        cout << data_center << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> row(n), column(n);
    for (int i = 0; i < n; i++) {
        cin >> row[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> column[i];
    }

    vector<vector<int>> portals;
    for (int i = 0; i < n; i++) {
        if (row[i] == column[n-1]) {
            row[i] = column[n-1] = -1;
            portals.push_back({i+1, 1, n, n});
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (row[n-1] == column[i]) {
            row[n-1] = column[i] = -1;
            portals.push_back({1, i+1, n, n});
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (row[i] != -1 && column[i] != -1) {
            portals.push_back({i+1, 1, row[i], n});
            portals.push_back({1, i+1, n, column[i]});
        }
    }

    cout << portals.size() << endl;
    for (auto portal : portals) {
        cout << portal[0] << " " << portal[1] << " " << portal[2] << " " << portal[3] << endl;
    }

    return 0;
}
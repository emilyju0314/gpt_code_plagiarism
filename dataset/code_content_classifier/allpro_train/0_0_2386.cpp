#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool hasPeriod(const string& s, int l, int r, int d) {
    for (int i = l; i <= r - d; i++) {
        if (s[i] != s[i + d]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string serialNumber;
    cin >> serialNumber;

    vector<pair<int, vector<int>>> changes;
    vector<tuple<int, int, int>> checks;

    for (int i = 0; i < m + k; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            changes.push_back({c, {l, r}});
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            checks.push_back({l, r, d});
        }
    }

    for (auto check : checks) {
        int l, r, d;
        tie(l, r, d) = check;
        bool passed = false;
        string editedSerialNumber = serialNumber;
        for (auto change : changes) {
            int c = change.first;
            for (int i = change.second[0] - 1; i < change.second[1]; i++) {
                editedSerialNumber[i] = c + '0';
            }
        }
        if (hasPeriod(editedSerialNumber, l - 1, r - 1, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
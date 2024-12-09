#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x1, x2;
    cin >> n >> x1 >> x2;

    vector<pair<int, int>> servers;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        servers.push_back({c, i});
    }

    sort(servers.begin(), servers.end());

    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < n; i++) {
        if (x1 <= servers[i].first) {
            idx1 = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (x2 <= servers[i].first) {
            idx2 = i;
            break;
        }
    }

    if (idx1 == -1 || idx2 == -1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << idx1 + 1 << " " << n - idx1 << endl;
        for (int i = 0; i <= idx1; i++) {
            cout << servers[i].second << " ";
        }
        cout << endl;
        for (int i = idx1 + 1; i < n; i++) {
            cout << servers[i].second << " ";
        }
        cout << endl;
    }

    return 0;
}
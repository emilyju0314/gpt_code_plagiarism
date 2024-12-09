#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << "1 1" << endl;
        return 0;
    }

    if (n == 1) {
        for (int i = 1; i <= m; i++) {
            cout << "1 " << i << endl;
        }
        return 0;
    }

    vector<pair<int, int>> path;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 == 1) {
                path.push_back({i, j});
            } else {
                path.push_back({i, m - j + 1});
            }
        }
    }

    for (const auto& p : path) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
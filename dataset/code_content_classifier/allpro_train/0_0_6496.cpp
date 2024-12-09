#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> rooks(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        rooks[a-1].push_back({1, 1 + rooks[0].size()});
        rooks[b-1].push_back({1, 2 + rooks[0].size()});
    }

    for (int i = 0; i < n; i++) {
        cout << rooks[i].size() << endl;
        for (int j = 0; j < rooks[i].size(); j++) {
            cout << rooks[i][j].first << " " << 2 * j + 1 << endl;
            cout << rooks[i][j].first << " " << 2 * j + 2 << endl;
        }
    }

    return 0;
}
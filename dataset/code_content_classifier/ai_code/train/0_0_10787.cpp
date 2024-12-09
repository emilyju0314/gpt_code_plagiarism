#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> rows, cols;
    vector<pair<int, int>> rooks;
    vector<int> answer;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        rooks.push_back({x, y});
        rows.insert(x);
        cols.insert(y);
        answer.push_back((n - rows.size()) * (n - cols.size()));
    }

    for (int ans : answer) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}
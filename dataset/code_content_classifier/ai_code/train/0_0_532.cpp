#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    unordered_set<int> unavailable;
    vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    auto isAttacked = [&](int new_x, int new_y, const unordered_set<int>& kings) {
        for(auto& dir : dirs) {
            int x = new_x + dir.first, y = new_y + dir.second;
            if(kings.count(x*m + y)) {
                return true;
            }
        }
        return false;
    };

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        int pos = x*m + y;

        if(unavailable.count(pos)) {
            unavailable.erase(pos);
        } else {
            unavailable.insert(pos);
        }

        unordered_set<int> kings;
        for(auto& cell : unavailable) {
            int row = cell / m, col = cell % m;
            if(!isAttacked(row, col, kings)) {
                kings.insert(cell);
            }
        }

        if(kings.size() >= n*m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
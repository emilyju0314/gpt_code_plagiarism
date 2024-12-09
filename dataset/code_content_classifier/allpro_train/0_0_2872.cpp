#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    unordered_set<int> unavailable;
    vector<int> row_count(2 * n, 0);
    vector<int> col_count(2 * m, 0);

    auto isAvailable = [&] (int i, int j) {
        return unavailable.find(i * (2 * m) + j) == unavailable.end();
    };

    auto setAvailable = [&] (int i, int j, bool available) {
        int cell = i * (2 * m) + j;
        if (available) {
            unavailable.erase(cell);
            row_count[i]--;
            col_count[j]--;
        } else {
            unavailable.insert(cell);
            row_count[i]++;
            col_count[j]++;
        }
    };

    auto canPlaceKings = [&] () {
        for (int i = 0; i < 2 * n; i++) {
            if (row_count[i] > 0) return false;
        }
        for (int j = 0; j < 2 * m; j++) {
            if (col_count[j] > 0) return false;
        }
        return true;
    };

    for (int i = 0; i < q; i++) {
        int query_i, query_j;
        cin >> query_i >> query_j;
        query_i--; query_j--;
        bool available = isAvailable(query_i, query_j);
        setAvailable(query_i, query_j, !available);

        if (canPlaceKings()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
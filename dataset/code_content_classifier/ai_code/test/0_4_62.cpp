#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    set<long long> staircases;
    long long num_staircases = 0;

    auto add_staircase = [&]() {
        num_staircases++;
        staircases.insert(num_staircases);
    };

    auto remove_staircase = [&]() {
        staircases.erase(num_staircases);
        num_staircases--;
    };

    auto count_staircase = [&](int x, int y) {
        if (matrix[x][y]) {
            matrix[x][y] = false;
            if (x > 0) {
                if (x < n - 1 && matrix[x - 1][y] && matrix[x + 1][y]) remove_staircase();
            }
            if (y > 0) {
                if (y < m - 1 && matrix[x][y - 1] && matrix[x][y + 1]) remove_staircase();
            }
        } else {
            matrix[x][y] = true;
            if (x > 0) {
                if (x < n - 1 && matrix[x - 1][y] && matrix[x + 1][y]) add_staircase();
            }
            if (y > 0) {
                if (y < m - 1 && matrix[x][y - 1] && matrix[x][y + 1]) add_staircase();
            }
        }
        cout << staircases.size() << endl;
    };

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        count_staircase(x - 1, y - 1);
    }

    return 0;
}
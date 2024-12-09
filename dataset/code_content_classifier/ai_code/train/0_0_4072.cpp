#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> elements(q);
    unordered_set<int> rows, cols;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        elements[i] = {r, c};
        rows.insert(r);
        cols.insert(c);
    }

    int num_rows = n - rows.size();
    int num_cols = m - cols.size();

    int num_elements = max(num_rows, num_cols);

    cout << num_elements << endl;

    return 0;
}
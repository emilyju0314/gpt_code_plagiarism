#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidConfiguration(vector<pair<int, int>> &rows, vector<pair<int, int>> &columns, vector<pair<char, int>> &strings) {
    for (auto s : strings) {
        char a = s.first;
        int p = s.second;

        if (a == 'L' || a == 'R') {
            if (rows[p].first < rows[p].second) return false;
        } else {
            if (columns[p].first < columns[p].second) return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> rows(n + 1, make_pair(0, n));
    vector<pair<int, int>> columns(m + 1, make_pair(0, m));
    vector<pair<char, int>> strings(n + m);

    for (int i = 0; i < n + m; i++) {
        char a, b;
        int p, q;
        cin >> a >> b >> p >> q;

        if (a == 'L' || a == 'T') rows[p].first = 1;
        if (a == 'R' || a == 'B') rows[p].second = n;

        if (b == 'L' || b == 'T') columns[q].first = 1;
        if (b == 'R' || b == 'B') columns[q].second = m;

        strings[i] = make_pair(a, p);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);

    do {
        vector<int> rowsOrder(order.begin(), order.end());
        vector<int> columnsOrder(order.begin(), order.end());

        for (int i = 0; i < n; i++) {
            rows[rowsOrder[i]] = make_pair(i + 1, i + 1);
        }

        for (int i = 0; i < m; i++) {
            columns[columnsOrder[i]] = make_pair(i + 1, i + 1);
        }

        if (isValidConfiguration(rows, columns, strings)) {
            for (int i = 0; i < n; i++) {
                cout << rowsOrder[i] << " ";
            }
            cout << endl;

            for (int i = 0; i < m; i++) {
                cout << columnsOrder[i] << " ";
            }
            cout << endl;

            return 0;
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << "No solution" << endl;

    return 0;
}
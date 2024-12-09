#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> rooks(k);
    vector<unordered_set<int>> rows(n+1), cols(m+1);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        rooks[i] = make_pair(x, y);
        rows[x].insert(y);
        cols[y].insert(x);
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        bool protected = false;
        for (int j = x1; j <= x2; j++) {
            if (rows[j].empty()) {
                protected = true;
                break;
            }
        }

        for (int j = y1; j <= y2; j++) {
            if (cols[j].empty()) {
                protected = true;
                break;
            }
        }

        if (protected) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
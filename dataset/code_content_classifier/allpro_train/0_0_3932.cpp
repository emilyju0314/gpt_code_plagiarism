#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<string>> warehouse(n, vector<string>(m, ""));
    vector<pair<string, pair<int, int>>> boxes;

    for (int i = 0; i < k; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            int x, y;
            string id;
            cin >> x >> y >> id;

            x--; y--;

            while (x < n) {
                if (warehouse[x][y] == "") {
                    warehouse[x][y] = id;
                    break;
                }
                y++;
                if (y == m) {
                    y = 0;
                    x++;
                }
            }
        } else if (op == '-') {
            string id;
            cin >> id;

            bool found = false;
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    if (warehouse[j][l] == id) {
                        cout << j+1 << " " << l+1 << endl;
                        found = true;
                        warehouse[j][l] = "";
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                cout << "-1 -1" << endl;
            }
        }
    }

    return 0;
}
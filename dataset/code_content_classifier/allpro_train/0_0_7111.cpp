#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj_matrix(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj_matrix[a][b] = adj_matrix[b][a] = true;
    }

    int max_dominoes = 0;
    for (int i = 1; i < (1 << n); i++) {
        int count = __builtin_popcount(i);
        vector<int> parity(n, -1);
        int valid = true;

        for (int a = 0; a < n; a++) {
            if (!(i & (1 << a))) continue;

            for (int b = a + 1; b < n; b++) {
                if (!(i & (1 << b))) continue;
                if (adj_matrix[a][b]) {
                    if (parity[a] == -1 && parity[b] == -1) {
                        parity[a] = parity[b] = count % 2;
                    } else if (parity[a] != parity[b] && (parity[a] != -1 && parity[b] != -1)) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (valid) {
            max_dominoes = max(max_dominoes, count);
        }
    }

    cout << max_dominoes << endl;

    return 0;
}
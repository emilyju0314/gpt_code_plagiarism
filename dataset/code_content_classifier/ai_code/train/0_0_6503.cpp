#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> table(n, vector<int>(m, 0)); // Initialize table with all green cells
    vector<vector<bool>> good_mood(n-1, vector<bool>(m-1, false));

    while (q--) {
        int a, l, r;
        cin >> a >> l >> r;
        a--; l--; r--;

        for (int i = l; i <= r; i++) {
            if (table[a][i] == 0) table[a][i] = 1; // Toggle color
            else table[a][i] = 0;
        }

        bool chameleon_good_mood = false;
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m-1; j++) {
                if (table[i][j] == table[i+1][j+1] && table[i][j+1] == table[i+1][j] && table[i][j] != table[i][j+1]) {
                    good_mood[i][j] = true;
                    chameleon_good_mood = true;
                }
            }
        }

        if (chameleon_good_mood) {
            bool found = false;
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < m-1; j++) {
                    if (good_mood[i][j] && !found) {
                        cout << i+1 << " " << j+1 << " " << i+2 << " " << j+2 << endl;
                        found = true;
                    }
                }
            }
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
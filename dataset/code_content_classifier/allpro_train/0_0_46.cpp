#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, r, c;
    cin >> n >> m;

    vector<string> cyclicTable(n);
    for(int i = 0; i < n; i++) {
        cin >> cyclicTable[i];
    }

    cin >> r >> c;

    vector<string> pattern(r);
    for(int i = 0; i < r; i++) {
        cin >> pattern[i];
    }

    vector<vector<int>> appearance(n, vector<int>(m, 0));

    for(int i = 0; i <= n - r; i++) {
        for(int j = 0; j <= m - c; j++) {
            bool match = true;

            for(int x = 0; x < r; x++) {
                for(int y = 0; y < c; y++) {
                    if(pattern[x][y] != '?' && pattern[x][y] != cyclicTable[(i + x) % n][(j + y) % m]) {
                        match = false;
                        break;
                    }
                }
                if(!match) {
                    break;
                }
            }

            if(match) {
                for(int x = 0; x < r; x++) {
                    for(int y = 0; y < c; y++) {
                        if(pattern[x][y] != '?') {
                            appearance[(i + x) % n][(j + y) % m] = 1;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << appearance[i][j];
        }
        cout << endl;
    }

    return 0;
}
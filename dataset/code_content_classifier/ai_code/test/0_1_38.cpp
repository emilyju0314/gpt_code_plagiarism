#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<char>> exitable(n, vector<char>(m, 'N'));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(grid[i][j] == 'X') {
                exitable[i][j] = 'N';
            } else {
                if(i+1 < n && exitable[i+1][j] == 'N') {
                    exitable[i][j] = 'Y';
                    fill(exitable[i].begin()+j+1, exitable[i].end(), 'N');
                }
                if(j+1 < m && exitable[i][j+1] == 'N') {
                    exitable[i][j] = 'Y';
                    for(int k = i+1; k < n; k++) {
                        exitable[k][j] = 'N';
                    }
                }
            }
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        x1--, x2--;

        bool determinable = true;
        for(int j = 0; j < n; j++) {
            if(exitable[j][x1] == 'N' || exitable[j][x2] == 'N') {
                determinable = false;
                break;
            }
        }

        cout << (determinable ? "YES" : "NO") << endl;
    }

    return 0;
}
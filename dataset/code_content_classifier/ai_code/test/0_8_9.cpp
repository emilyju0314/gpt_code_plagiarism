#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> direction(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> direction[i][j];
        }
    }

    vector<int> columns(k);
    for(int i = 0; i < k; i++) {
        cin >> columns[i];
    }

    for(int i = 0; i < k; i++) {
        int current_col = columns[i];
        for(int row = 0; row < n; row++) {
            if(direction[row][current_col-1] == 1) {
                current_col++;
            } else if(direction[row][current_col-1] == 3) {
                current_col--;
            }
        }
        cout << current_col << " ";
    }

    return 0;
}
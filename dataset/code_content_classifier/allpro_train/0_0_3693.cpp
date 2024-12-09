#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> row_sum(n, 0);
    vector<int> col_sum(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
        }
    }

    vector<string> moves;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((row_sum[i] + col_sum[j] - grid[i][j]) % (n + m) != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        while(row_sum[i] > 0) {
            cnt++;
            moves.push_back("row " + to_string(i+1));
            row_sum[i]--;
        }
    }

    for(int j = 0; j < m; j++) {
        while(col_sum[j] > 0) {
            cnt++;
            moves.push_back("col " + to_string(j+1));
            col_sum[j]--;
        }
    }

    cout << cnt << endl;
    for(const string& move : moves) {
        cout << move << endl;
    }

    return 0;
}
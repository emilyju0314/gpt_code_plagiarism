#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++) {
            grid[i][j] = row[j] - '0';
        }
    }

    vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int zeros = prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] + prefix[a-1][b-1];
        int result = (c - a + 1) * (d - b + 1) - zeros;
        cout << result << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> matrix;
int max_sum = 0;

void dfs(int row, int selected_count, int sum) {
    if(row == n) {
        if(selected_count <= m/2 && sum % k == 0) {
            max_sum = max(max_sum, sum);
        }
        return;
    }

    dfs(row+1, selected_count, sum);

    for(int i = 0; i < m; i++) {
        dfs(row+1, selected_count+1, sum + matrix[row][i]);
    }
}

int main() {
    cin >> n >> m >> k;
    matrix.resize(n, vector<int>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << max_sum << endl;

    return 0;
}
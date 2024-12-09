#include <iostream>
#include <vector>

using namespace std;

bool check_perfect_coloring_cut(vector<vector<int>>& matrix, int n, int m) {
    vector<char> row_color(n, 'R');
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] <= matrix[i][0]) {
                row_color[i] = 'B';
                break;
            }
        }
    }

    bool red_in_left = false, blue_in_right = false;
    int cut_index = -1;
    for (int k = 1; k < m; k++) {
        bool valid_cut = true;
        for (int i = 0; i < n; i++) {
            if (row_color[i] == 'R' && matrix[i][k] <= matrix[i][0]) {
                valid_cut = false;
                break;
            }
            if (row_color[i] == 'B' && matrix[i][k] >= matrix[i][0]) {
                valid_cut = false;
                break;
            }
        }
        if (valid_cut) {
            red_in_left = true;
            blue_in_right = true;
            cut_index = k;
            break;
        }
    }

    if (!red_in_left || !blue_in_right || cut_index == -1) {
        return false;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << row_color[i];
    }
    cout << " " << cut_index << endl;
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        if (!check_perfect_coloring_cut(matrix, n, m)) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
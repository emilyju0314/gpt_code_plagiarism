#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> copies(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> copies[i][j];
        }
    }

    vector<int> restored_array(m);
    bool found = false;
    for (int i = 0; i < m; i++) {
        vector<int> possible_values = {copies[0][i]};
        if (n > 1) possible_values.push_back(copies[1][i]);
        if (n > 2) possible_values.push_back(copies[2][i]);

        for (int value : possible_values) {
            restored_array[i] = value;
            int diff_count = 0;
            for (int j = 0; j < n; j++) {
                int mismatches = 0;
                for (int k = 0; k < m; k++) {
                    if (copies[j][k] != restored_array[k]) {
                        mismatches++;
                    }
                }
                if (mismatches > 2) {
                    diff_count++;
                    break;
                }
            }
            if (diff_count == 0) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (found) {
        cout << "Yes" << endl;
        for (int i = 0; i < m; i++) {
            cout << restored_array[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
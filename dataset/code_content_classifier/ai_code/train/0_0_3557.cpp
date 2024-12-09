#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> table(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> table[i][j];
        }
    }

    vector<int> row_values(n, 0);
    vector<int> col_values(m, 0);

    bool possible = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(table[i][j] == '>') {
                row_values[i] = max(row_values[i], col_values[j] + 1);
            } else if(table[i][j] == '<') {
                col_values[j] = max(col_values[j], row_values[i] + 1);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(table[i][j] == '>') {
                if(row_values[i] <= col_values[j]) {
                    possible = false;
                    break;
                }
            } else if(table[i][j] == '<') {
                if(col_values[j] <= row_values[i]) {
                    possible = false;
                    break;
                }
            } else {
                if(row_values[i] != col_values[j]) {
                    possible = false;
                    break;
                }
            }
        }
    }

    if(possible) {
        cout << "Yes\n";
        for(int i = 0; i < n; i++) {
            cout << row_values[i] << " ";
        }
        cout << "\n";
        for(int i = 0; i < m; i++) {
            cout << col_values[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
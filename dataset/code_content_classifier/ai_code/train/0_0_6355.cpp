#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool found = false;
    for(int i = 0; i < n; i++) {
        bool row_has_positive = false;
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] > 0) {
                row_has_positive = true;
                break;
            }
        }
        if(row_has_positive) {
            for(int j = 0; j < n; j++) {
                if(matrix[j][i] > 0) {
                    found = true;
                    break;
                }
            }
        }
    }

    if(found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
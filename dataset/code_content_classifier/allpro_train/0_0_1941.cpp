#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m*2));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m*2; j++) {
            char c;
            cin >> c;
            matrix[i][j] = c - '0'; // convert char to int
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m*2; j+=2) {
            if(matrix[i][j] + matrix[i][j+1] == 1) {
                matrix[i][j] = 1;
                matrix[i][j+1] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m*2; j++) {
            cout << matrix[i][j];
            if(j % 2 == 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
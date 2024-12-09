#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 3) {
        cout << -1 << endl;
    } else {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
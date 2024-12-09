#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m, k;
        cin >> m >> k;

        vector<int> numbers(k);
        for (int j = 0; j < k; j++) {
            cin >> numbers[j];
        }

        int n = 0;
        for (int j = 0; j < k; j++) {
            n = max(n, (int)ceil(sqrt(numbers[j])));
        }

        cout << n << endl;

        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int row = 0, col = 0;
        for (int j = 0; j < k; j++) {
            int num = numbers[j];
            for (int l = 0; l < num; l++) {
                matrix[row][col] = j + 1;
                col++;
                if (col == n) {
                    col = 0;
                    row++;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                cout << matrix[j][l] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
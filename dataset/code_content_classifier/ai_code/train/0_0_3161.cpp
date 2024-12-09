#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> matrix(n, vector<int>(m, 0));

    for(int i = 0; i < q; i++) {
        int ti;
        cin >> ti;

        if(ti == 1) {
            int ri;
            cin >> ri;
            ri--;

            vector<int> temp = matrix[ri];
            matrix[ri] = vector<int>(m);
            for(int j = 0; j < m; j++) {
                matrix[ri][j] = temp[(j + 1) % m];
            }
        } else if(ti == 2) {
            int ci;
            cin >> ci;
            ci--;

            vector<int> temp;
            for(int j = 0; j < n; j++) {
                temp.push_back(matrix[j][ci]);
            }
            for(int j = 0; j < n; j++) {
                matrix[j][ci] = temp[(j + 1) % n];
            }
        } else {
            int ri, ci, xi;
            cin >> ri >> ci >> xi;
            ri--, ci--;
            matrix[ri][ci] = xi;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
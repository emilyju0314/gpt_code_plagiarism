#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int t = 0; t < q; t++) {
        int ai, bi, ci, di, hi, wi;
        cin >> ai >> bi >> ci >> di >> hi >> wi;

        for(int i = 0; i < hi; i++) {
            for(int j = 0; j < wi; j++) {
                swap(matrix[ai-1+i][bi-1+j], matrix[ci-1+i][di-1+j]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
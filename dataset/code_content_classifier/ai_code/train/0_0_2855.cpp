#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> rowXor(n);
    vector<int> colXor(m);

    for (int i = 0; i < n; i++) {
        cin >> rowXor[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> colXor[i];
    }

    // Check if it's possible to construct a matrix satisfying the constraints
    int totalXor = 0;
    for (int i = 0; i < n; i++) {
        totalXor ^= rowXor[i];
    }
    for (int i = 0; i < m; i++) {
        totalXor ^= colXor[i];
    }

    if (totalXor != 0) {
        cout << "NO" << endl;
        return 0;
    }

    // Construct the matrix
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j < m - 1) {
                cout << (rowXor[i] ^ colXor[j]) << " ";
            } else {
                cout << (rowXor[i] ^ colXor[j]) << endl;
            }
        }
    }

    return 0;
}
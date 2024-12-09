#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    bool found = false;
    vector<int> result(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            result[i] = j;
            int xor_val = matrix[0][0];
            for(int k = 1; k < n; k++) {
                xor_val ^= matrix[k][result[k]];
            }
            if(xor_val > 0) {
                found = true;
                break;
            }
        }
        if(found) {
            break;
        }
    }

    if(found) {
        cout << "TAK" << endl;
        for(int i = 0; i < n; i++) {
            cout << result[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "NIE" << endl;
    }

    return 0;
}
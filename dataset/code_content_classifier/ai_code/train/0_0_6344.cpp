#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, k;
    cin >> m >> k;

    vector<vector<int>> pos(k, vector<int>(m));
    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> pos[i][j];
        }
    }

    int modified = -1;
    for (int i = 1; i < k - 1; ++i) {
        bool found = false;
        for (int j = 0; j < m; ++j) {
            if (pos[i][j] != pos[0][j]) {
                if (modified != -1) {
                    cout << i << " " << pos[i][j] << endl;
                    cout.flush(); // flush the output buffer
                    return 0;
                }
                modified = j;
                break;
            }
        }
    }

    return 0;
}
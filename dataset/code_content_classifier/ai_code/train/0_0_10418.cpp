#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, k;
    cin >> m >> k;

    vector<vector<int>> positions(k, vector<int>(m));
    
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < m; j++) {
            cin >> positions[i][j];
        }
    }

    int y = -1, p = -1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k - 1; j++) {
            if(positions[j][i] != positions[j + 1][i]) {
                y = j + 1;
                p = positions[j + 1][i];
                break;
            }
        }
        if(y != -1) {
            break;
        }
    }

    cout << y << " " << p << endl;
    cout << flush;

    return 0;
}
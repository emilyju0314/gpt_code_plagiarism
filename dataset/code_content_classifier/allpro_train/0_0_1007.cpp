#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> current(n, vector<char>(m));
    vector<vector<char>> desired(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> current[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> desired[i][j];
        }
    }

    vector<pair<int, int>> operations;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            if(current[i][j] != desired[i][j]) {
                operations.push_back({i+1, j+1});
                for(int di = 0; di < 2; di++) {
                    for(int dj = 0; dj < 2; dj++) {
                        if(current[i+di][j+dj] == 'L') current[i+di][j+dj] = 'R';
                        else if(current[i+di][j+dj] == 'R') current[i+di][j+dj] = 'L';
                        else if(current[i+di][j+dj] == 'U') current[i+di][j+dj] = 'D';
                        else if(current[i+di][j+dj] == 'D') current[i+di][j+dj] = 'U';
                    }
                }
            }
        }
    }

    cout << operations.size() << endl;
    for(auto op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}
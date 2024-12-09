#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> paths(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> paths[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            random_shuffle(paths[i].begin(), paths[i].end());
            for(int j = 0; j < m; j++) {
                cout << paths[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
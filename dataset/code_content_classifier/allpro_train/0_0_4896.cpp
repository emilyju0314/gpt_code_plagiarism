#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> plan(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> plan[i][j];
        }
    }

    int goodPositions = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(plan[i][j] == 0) {
                // Check left
                for(int k = j-1; k >= 0; k--) {
                    if(plan[i][k] == 1) {
                        goodPositions++;
                        break;
                    }
                }

                // Check right
                for(int k = j+1; k < m; k++) {
                    if(plan[i][k] == 1) {
                        goodPositions++;
                        break;
                    }
                }

                // Check up
                for(int k = i-1; k >= 0; k--) {
                    if(plan[k][j] == 1) {
                        goodPositions++;
                        break;
                    }
                }

                // Check down
                for(int k = i+1; k < n; k++) {
                    if(plan[k][j] == 1) {
                        goodPositions++;
                        break;
                    }
                }
            }
        }
    }

    cout << goodPositions << endl;

    return 0;
}
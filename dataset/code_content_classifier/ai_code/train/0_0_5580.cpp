#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> times(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> times[i][j];
        }
    }

    vector<int> results(m, 0);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(j == 0) {
                results[i] += times[i][j];
            } else {
                results[i] = max(results[i], results[i-1]) + times[i][j];
            }
        }
    }

    for(int i = 0; i < m; i++) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}
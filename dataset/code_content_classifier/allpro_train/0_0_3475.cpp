#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> bubblefield(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> bubblefield[i][j];
        }
    }

    vector<int> rows(N), cols(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            rows[i] += bubblefield[i][j];
            cols[j] += bubblefield[i][j];
        }
    }

    sort(rows.rbegin(), rows.rend());
    sort(cols.rbegin(), cols.rend());

    int maxBubbles = max(rows[0] + rows[1] + rows[2] + rows[3], cols[0] + cols[1] + cols[2] + cols[3);
    cout << maxBubbles << endl;

    return 0;
}
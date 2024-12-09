#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> requests(N);
    for (int i = 0; i < N; i++) {
        cin >> requests[i];
    }

    int midRow = (K + 1) / 2;

    for (int i = 0; i < N; i++) {
        int M = requests[i];
        int minRemoteness = INT_MAX;
        int row, yl, yr;

        for (int r = 1; r <= K; r++) {
            for (int y = 1; y <= K - M + 1; y++) {
                int center = abs(midRow - r);
                int remoteness = center + abs(midRow - r) + abs(midRow - r);

                if (remoteness < minRemoteness) {
                    minRemoteness = remoteness;
                    row = r;
                    yl = y;
                    yr = y + M - 1;
                }
            }
        }

        if (minRemoteness == INT_MAX) {
            cout << "-1" << endl;
        } else {
            cout << row << " " << yl << " " << yr << endl;
        }
    }

    return 0;
}
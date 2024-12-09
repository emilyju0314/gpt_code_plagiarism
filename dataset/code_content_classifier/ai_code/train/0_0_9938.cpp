#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<vector<int>> grid(N, vector<int>(1000000000, 1));

    for (int i = 0; i < N; i++) {
        int minH = INT_MAX;
        for (int j = max(0, i - K); j <= min(i, i + K); j++) {
            minH = min(minH, H[j]);
        }
        for (int j = 0; j < minH; j++) {
            grid[i][j] = 0;
        }
    }

    int ops = 0;
    for (int j = 0; j < 1000000000; j++) {
        bool paint = false;
        for (int i = 0; i < N; i++) {
            if (grid[i][j] == 1) {
                paint = true;
                break;
            }
        }
        if (paint) {
            ops++;
        }
    }

    cout << ops << endl;

    return 0;
}
#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    long long ans = 0;

    for (int row_subset = 0; row_subset < (1 << N); row_subset++) {
        for (int col_subset = 0; col_subset < (1 << M); col_subset++) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                if (row_subset & (1 << i)) {
                    for (int j = 0; j < M; j++) {
                        if (col_subset & (1 << j)) {
                            sum += grid[i][j];
                        }
                    }
                }
            }
            if (sum % 2 != 0) {
                ans++;
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
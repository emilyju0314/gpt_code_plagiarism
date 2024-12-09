#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 998244353;

int main() {
    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int ans = 1;
    for (int i = 1; i < N-1; i++) {
        int count_o = 0, count_x = 0;
        for (int j = 1; j < N-1; j++) {
            if (grid[i][j] == 'o') {
                count_o++;
            } else if (grid[i][j] == 'x') {
                count_x++;
            }
        }

        if (count_o == 0 && count_x == 0) {
            ans = (ans * 2) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
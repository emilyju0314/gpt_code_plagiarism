#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000003;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int count = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int cnt = 0;

                if (i > 0 && grid[i-1][j] == '.') cnt++;
                if (i < n-1 && grid[i+1][j] == '.') cnt++;
                if (j > 0 && grid[i][j-1] == '.') cnt++;
                if (j < m-1 && grid[i][j+1] == '.') cnt++;

                count = (count * cnt) % MOD;
            }
        }
    }

    cout << count << endl;

    return 0;
}
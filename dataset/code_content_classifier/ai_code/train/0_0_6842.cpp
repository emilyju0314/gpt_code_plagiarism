#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> permutations(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> permutations[i][j];
        }
    }

    int common_prefix = n;
    int common_suffix = n;
    for(int i = 1; i < m; i++) {
        int prefix = 0;
        while(prefix < common_prefix && permutations[i][prefix] == permutations[i-1][prefix]) {
            prefix++;
        }
        common_prefix = min(common_prefix, prefix);

        int suffix = 0;
        while(suffix < common_suffix && permutations[i][n-suffix-1] == permutations[i-1][n-suffix-1]) {
            suffix++;
        }
        common_suffix = min(common_suffix, suffix);
    }

    cout << max(common_suffix + common_prefix, 0) << endl;

    return 0;
}
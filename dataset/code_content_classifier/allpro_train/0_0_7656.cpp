#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> piles(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        piles[i] = vector<int>(s);
        for (int j = 0; j < s; j++) {
            cin >> piles[i][j];
        }
    }

    vector<vector<int>> dpCiel(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dpJiro(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        dpCiel[i][i] = piles[i-1][0];
        dpJiro[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dpCiel[i][j] = max(piles[i-1][0] + dpJiro[i+1][j], piles[j-1][0] + dpJiro[i][j-1]);
            dpJiro[i][j] = max(dpCiel[i+1][j], dpCiel[i][j-1]);
        }
    }

    cout << dpCiel[1][n] << " " << dpJiro[1][n] << endl;

    return 0;
}
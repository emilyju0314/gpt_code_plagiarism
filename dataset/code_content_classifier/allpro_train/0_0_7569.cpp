#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp1(n, vector<int>(m)), dp2(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp1[i][j] = a[i][j] + max((i > 0 ? dp1[i-1][j] : 0), (j > 0 ? dp1[i][j-1] : 0));
        }
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            dp2[i][j] = a[i][j] + max((i < n-1 ? dp2[i+1][j] : 0), (j > 0 ? dp2[i][j-1] : 0));
        }
    }

    int max_gain = 0;

    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            max_gain = max(max_gain, dp1[i-1][j] + dp2[i+1][j] + dp1[i][j-1] + dp2[i][j+1]);
        }
    }

    cout << max_gain << endl;

    return 0;
}
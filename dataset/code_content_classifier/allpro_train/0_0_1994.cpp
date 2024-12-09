#include <iostream>
#include <vector>

using namespace std;

int n, m;
long long k;
vector<vector<long long>> grid;
vector<vector<vector<long long>> > dp;

long long countPaths(int i, int j, long long xorSum) {
    if(i >= n || j >= m) {
        return 0;
    }
    if (i == n-1 && j == m-1) {
        return xorSum == k;
    }
    if(dp[i][j][xorSum] != -1) {
        return dp[i][j][xorSum];
    }

    long long newSum = xorSum ^ grid[i][j];
    long long paths = countPaths(i+1, j, newSum) + countPaths(i, j+1, newSum);

    return dp[i][j][xorSum] = paths;
}

int main() {
    cin >> n >> m >> k;
    grid.resize(n, vector<long long>(m));
    dp.resize(n, vector<vector<long long>>(m, vector<long long>((1<<20), -1));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countPaths(0, 0, 0) << endl;

    return 0;
}
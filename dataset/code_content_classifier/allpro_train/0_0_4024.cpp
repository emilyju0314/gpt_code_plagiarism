#include <iostream>
#include <vector>

using namespace std;

int countDistinctWays(vector<vector<char>>& city, int n, int m) {
    int count = 0;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (city[i][j] == '.') {
                if (city[i-1][j] == '.' && city[i+1][j] == '.' && city[i][j-1] == '.' && city[i][j+1] == '.') {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> city(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> city[i][j];
        }
    }

    cout << countDistinctWays(city, n, m) << endl;

    return 0;
}
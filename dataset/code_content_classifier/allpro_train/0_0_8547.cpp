#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<pair<int, pair<int, int>>> values;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            values.push_back({grid[i][j], {i, j}});
        }
    }

    sort(values.rbegin(), values.rend());

    vector<vector<char>> result(N, vector<char>(N, '.'));

    long long total = 0;
    for (int i = 0; i < K * K; i++) {
        total += values[i].first;
        result[values[i].second.first][values[i].second.second] = 'X';
    }

    cout << total << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }

    return 0;
}
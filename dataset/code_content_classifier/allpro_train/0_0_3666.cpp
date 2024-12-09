#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));

    vector<pair<int, int>> stars;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '*') {
                stars.push_back(make_pair(i, j));
            }
        }
    }

    int fourth_row, fourth_col;

    if (stars[0].first == stars[1].first) {
        fourth_row = stars[2].first;
    } else if (stars[0].first == stars[2].first) {
        fourth_row = stars[1].first;
    } else {
        fourth_row = stars[0].first;
    }

    if (stars[0].second == stars[1].second) {
        fourth_col = stars[2].second;
    } else if (stars[0].second == stars[2].second) {
        fourth_col = stars[1].second;
    } else {
        fourth_col = stars[0].second; 
    }

    cout << fourth_row + 1 << " " << fourth_col + 1 << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> island(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> island[i][j];
        }
    }

    int k;
    cin >> k;

    vector<pair<char, pair<int, int>>> sights;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] >= 'A' && island[i][j] <= 'Z') {
                sights.push_back({island[i][j], {i, j}});
            }
        }
    }

    sort(sights.begin(), sights.end());
    
    string result = "";
    for (int i = 0; i < k; i++) {
        char dir;
        int len;
        cin >> dir >> len;
        
        int x = sights[0].second.first;
        int y = sights[0].second.second;

        if (dir == 'N') {
            x -= len;
        } else if (dir == 'S') {
            x += len;
        } else if (dir == 'W') {
            y -= len;
        } else if (dir == 'E') {
            y += len;
        }

        bool valid = false;
        for (int j = 0; j < sights.size(); j++) {
            int new_x = sights[j].second.first;
            int new_y = sights[j].second.second;

            if (new_x == x && new_y == y) {
                valid = true;
                break;
            }
        }

        if (valid) {
            result += sights[0].first;
        }

    }

    if (result == "") {
        cout << "no solution" << endl;
    } else {
        sort(result.begin(), result.end());
        cout << result << endl;
    }

    return 0;
}
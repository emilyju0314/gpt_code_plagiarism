#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> heights(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }

    vector<pair<pair<int, int>, int>> construction_sites;

    for(int i = 0; i <= n - a; i++) {
        for(int j = 0; j <= m - b; j++) {
            int min_height = INT_MAX;
            for(int x = i; x < i + a; x++) {
                for(int y = j; y < j + b; y++) {
                    min_height = min(min_height, heights[x][y]);
                }
            }
            for(int x = i; x < i + a; x++) {
                for(int y = j; y < j + b; y++) {
                    construction_sites.push_back({{x + 1, y + 1}, heights[x][y] - min_height});
                }
            }
        }
    }

    sort(construction_sites.begin(), construction_sites.end());

    vector<pair<int, int>> buildings;
    for(auto site : construction_sites) {
        if(find(buildings.begin(), buildings.end(), site.first) == buildings.end()) {
            buildings.push_back(site.first);
            cout << site.first.first << " " << site.first.second << " " << site.second << endl;
        }
    }

    return 0;
}
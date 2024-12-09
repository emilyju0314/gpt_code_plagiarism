#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> nearCities(n);
    unordered_map<int, int> cityIndex;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        nearCities[i].resize(k);

        for (int j = 0; j < k; ++j) {
            cin >> nearCities[i][j];
            cityIndex[nearCities[i][j]] = i;
        }
    }

    vector<pair<int, int>> roads;
    for (int i = 1; i <= n; ++i) {
        if (cityIndex.find(i) != cityIndex.end()) {
            int city1 = cityIndex[i];

            for (int j = 0; j < nearCities[city1].size(); ++j) {
                int city2 = cityIndex[nearCities[city1][j]];

                if (city1 != city2) {
                    roads.push_back({min(city1, city2), max(city1, city2)});
                }
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << roads[i].first + 1 << " " << roads[i].second + 1 << endl;
    }

    return 0;
}
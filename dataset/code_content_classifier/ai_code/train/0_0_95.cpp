#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countPairsThroughFairs(int n, int m, int a, int b, vector<pair<int, int>> roads) {
    int total_pairs = n * (n - 2); // Start with all possible pairs
  
    // Remove pairs where x is a or b
    total_pairs -= (n - 1);

    // Remove pairs where y is a or b
    total_pairs -= (n - 1);

    // Find cities reachable from a
    unordered_set<int> cities_reachable_from_a;
    for (auto& road : roads) {
        if (road.first == a) {
            cities_reachable_from_a.insert(road.second);
        }
        if (road.second == a) {
            cities_reachable_from_a.insert(road.first);
        }
    }

    // Find cities reachable from b
    unordered_set<int> cities_reachable_from_b;
    for (auto& road : roads) {
        if (road.first == b) {
            cities_reachable_from_b.insert(road.second);
        }
        if (road.second == b) {
            cities_reachable_from_b.insert(road.first);
        }
    }

    // Find the intersection between cities reachable from a and cities reachable from b
    int common_cities = 0;
    for (int city : cities_reachable_from_a) {
        if (cities_reachable_from_b.find(city) != cities_reachable_from_b.end()) {
            common_cities++;
        }
    }

    // Subtract pairs that don't require going through both fairs
    total_pairs -= (common_cities * (common_cities - 1) / 2);

    return total_pairs;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<pair<int, int>> roads;
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            roads.push_back({u, v});
        }

        cout << countPairsThroughFairs(n, m, a, b, roads) << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacentCities(n+1);
    set<pair<int, int>> roads;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacentCities[a].push_back(b);
        adjacentCities[b].push_back(a);
        roads.insert({a, b});
        roads.insert({b, a});
    }

    int max_episodes = 0;
    vector<vector<int>> episodes;

    for (int city = 1; city <= n; city++) {
        for (int neighbor : adjacentCities[city]) {
            for (int secondNeighbor : adjacentCities[neighbor]) {
                if (city != secondNeighbor && roads.count({secondNeighbor, city}) == 0) {
                    max_episodes++;
                    episodes.push_back({city, neighbor, secondNeighbor});
                }
            }
        }
    }

    cout << max_episodes << endl;
    for (vector<int>& episode : episodes) {
        for (int city : episode) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}
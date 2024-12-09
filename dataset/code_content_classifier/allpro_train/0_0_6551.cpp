#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> bus_routes(N + 1);
    vector<vector<int>> train_routes(N + 1);
    
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        bus_routes[u].push_back(v);
        bus_routes[v].push_back(u);
    }

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        train_routes[u].push_back(v);
        train_routes[v].push_back(u);
    }

    vector<int> mapping(N + 1, 0);
    unordered_set<int> used;
    bool possible = true;

    for (int i = 1; i <= N; i++) {
        int bus_city = i;
        int train_city = i + N;

        if (mapping[bus_city] == 0) {
            if (bus_routes[bus_city].size() == train_routes[train_city].size()) {
                for (int neighbor : bus_routes[bus_city]) {
                    if (mapping[neighbor] != 0 && mapping[neighbor] != train_city) {
                        possible = false;
                        break;
                    }
                    mapping[neighbor] = train_city;
                }
                mapping[bus_city] = train_city;
            } else {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        cout << "Yes\n";
        for (int i = 1; i <= N; i++) {
            cout << mapping[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No\n";
    }

    return 0;
}
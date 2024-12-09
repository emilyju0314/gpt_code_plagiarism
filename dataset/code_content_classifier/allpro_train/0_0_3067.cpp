#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> animals(n);
    for(int i = 0; i < n; i++) {
        cin >> animals[i];
    }

    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    double sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int min_animals = min(animals[i], animals[j]);
            for(auto u : adj[i]) {
                if(u != j) {
                    min_animals = min(min_animals, animals[u]);
                }
            }
            sum += min_animals;
        }
    }

    double result = (2 * sum) / (n * (n - 1));
    cout << setprecision(10) << fixed << result << endl;

    return 0;
}
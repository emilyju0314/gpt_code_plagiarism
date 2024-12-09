#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct City {
    int enjoyment;
    int maxEnjoyment;
    int maxToll;
};

// Function to perform DFS and calculate maximum enjoyment and maximum toll cost for each city
void DFS(vector<vector<pair<int, pair<int, int>>>& graph, vector<City>& cities, int curr, int prev, int enjoyment, int toll) {
    City& city = cities[curr];
    city.enjoyment = enjoyment;
    city.maxEnjoyment = enjoyment;
    city.maxToll = toll;

    for (auto neighbor : graph[curr]) {
        int next = neighbor.first;
        if (next != prev) {
            int newEnjoyment = enjoyment;
            int newToll = max(toll, neighbor.second.second);

            DFS(graph, cities, next, curr, newEnjoyment, newToll);

            city.maxEnjoyment = max(city.maxEnjoyment, cities[next].maxEnjoyment);
            city.maxToll = max(city.maxToll, cities[next].maxToll);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<City> cities(n);
    vector<vector<pair<int, pair<int, int>>> graph(n);

    for (int i = 0; i < n; i++) {
        cin >> cities[i].enjoyment;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--; b--;
        graph[a].push_back({b, {c, t});
        graph[b].push_back({a, {c, t});
    }

    DFS(graph, cities, 0, -1, cities[0].enjoyment, 0);

    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;
        x--;

        int maxEnjoyment = cities[x].maxEnjoyment;
        int maxToll = cities[x].maxToll;

        int costPerVehicle = maxToll; // Amount of money per vehicle Omkar needs to guarantee reimbursement
        
        cout << maxEnjoyment << " " << costPerVehicle << endl;
    }

    return 0;
}
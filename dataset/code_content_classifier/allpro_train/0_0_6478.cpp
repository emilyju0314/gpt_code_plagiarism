#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> graph(m + 1, vector<int>());
    vector<int> inDegree(m + 1, 0);
    vector<int> order;
    vector<pair<int, int>> testimonies;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        inDegree[y]++;
        graph[x].push_back(y);
        testimonies.push_back(make_pair(x, y));
    }

    // Find the suspect who entered the room last
    int lastSuspect = 0;
    for (int i = 1; i <= m; i++) {
        if (inDegree[i] == 0) {
            lastSuspect = i;
            break;
        }
    }

    order.push_back(lastSuspect);

    // Determine the order of entry of the suspects
    while (order.size() < m) {
        for (int i = 0; i < testimonies.size(); i++) {
            if (testimonies[i].first == lastSuspect) {
                int nextSuspect = testimonies[i].second;
                inDegree[nextSuspect]--;
                if (inDegree[nextSuspect] == 0) {
                    order.push_back(nextSuspect);
                    lastSuspect = nextSuspect;
                }
            }
        }
    }

    // Sort the order in ascending order to print
    sort(order.begin(), order.end());

    // Print the order of suspects
    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << endl;
    }

    return 0;
}
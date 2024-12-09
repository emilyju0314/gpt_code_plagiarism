#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int cost;

    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<Edge>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(Edge(v, w));
            adj[v].push_back(Edge(u, w));
        }

        int l;
        cin >> l;
        map<string, pair<int, int>> mailItems; // pair<arrival time, sender post office>
        for (int i = 0; i < l; i++) {
            int sender, dest, time;
            string label;
            cin >> sender >> dest >> time >> label;
            mailItems[label] = make_pair(time, sender);
        }

        map<string, int> arrivalTimes; // final arrival times at destination post office
        for (auto& mail : mailItems) {
            string label = mail.first;
            int time = mail.second.first;
            int currPostOffice = mail.second.second;
            queue<pair<int, string>> q; // pair<time, label>
            q.push(make_pair(time, label));

            while (!q.empty()) {
                int t = q.front().first;
                string lab = q.front().second;
                q.pop();

                for (auto& edge : adj[currPostOffice]) {
                    int nextPostOffice = edge.to;
                    int cost = edge.cost;

                    if (nextPostOffice == dest) {
                        arrivalTimes[lab] = t + cost;
                    } else {
                        q.push(make_pair(t + cost, lab));
                    }
                }
            }
        }

        // Output the arrival times at destination post office
        vector<pair<string, int>> sortedArrivals(arrivalTimes.begin(), arrivalTimes.end());
        sort(sortedArrivals.begin(), sortedArrivals.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        for (auto& mail : sortedArrivals) {
            cout << mail.first << " " << mail.second << endl;
        }
        cout << endl;
    }

    return 0;
}
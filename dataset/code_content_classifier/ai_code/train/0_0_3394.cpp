#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> topics(n + 1);
    vector<set<int>> covered_topics(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> topics[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq; // Min priority queue

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> order;

    while (!pq.empty()) {
        int blog = pq.top();
        pq.pop();
        order.push_back(blog);

        for (int neighbor : graph[blog]) {
            in_degree[neighbor]--;
            covered_topics[neighbor].insert(topics[blog]);

            if (in_degree[neighbor] == 0) {
                bool found = false;
                for (int j = 1; j <= n; j++) {
                    if (covered_topics[neighbor].find(j) == covered_topics[neighbor].end()) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << -1 << endl;
                    return 0;
                }
                pq.push(neighbor);
            }
        }
    }

    if (order.size() != n) {
        cout << -1 << endl;
    } else {
        for (int blog : order) {
            cout << blog << " ";
        }
        cout << endl;
    }

    return 0;
}
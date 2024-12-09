#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) {
        pq.push(-i);
    }

    vector<int> priorities(n+1, 1);
    
    while(q--) {
        string query;
        cin >> query;

        if(query == "up") {
            int v;
            cin >> v;
            int new_priority = 1 + priorities[1];
            priorities[v] = new_priority;
            pq.push(-new_priority);
        } else if(query == "when") {
            int v;
            cin >> v;
            int steps = 1;
            while(true) {
                int top = -pq.top();
                pq.pop();
                if(priorities[v] == top) {
                    cout << steps << endl;
                    break;
                }
                steps++;
            }
        } else if(query == "compare") {
            int v, u;
            cin >> v >> u;
            int steps_v = 0, steps_u = 0;
            vector<int> pq_copy = pq;
            while(true) {
                int top = -pq_copy.top();
                pq_copy.pop();
                if(priorities[v] == top) {
                    steps_v = steps_v;
                    break;
                }
                steps_v++;
            }
            pq_copy = pq;
            while(true) {
                int top = -pq_copy.top();
                pq_copy.pop();
                if(priorities[u] == top) {
                    steps_u = steps_u;
                    break;
                }
                steps_u++;
            }
            if(steps_v < steps_u) {
                cout << v << endl;
            } else {
                cout << u << endl;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    vector<int> neighbors;
    int color = 0; // 0 for white, 1 for black
};

int main() {
    int n;
    cin >> n;

    vector<Node> graph(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].neighbors.push_back(i);
        graph[u].neighbors.push_back(v);
        graph[v].neighbors.push_back(i);
        graph[v].neighbors.push_back(u);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int id;
            cin >> id;
            graph[id].color = 1;
        } else if (type == 2) {
            int id;
            cin >> id;
            graph[id].color = 0;
        } else {
            int a, b;
            cin >> a >> b;

            if (a == b) {
                cout << "0" << endl;
                continue;
            }

            queue<int> q;
            vector<bool> visited(n + 1, false);
            q.push(a);
            visited[a] = true;
            bool found = false;
            int distance = 0;

            while (!q.empty()) {
                int size = q.size();
                
                for (int j = 0; j < size; j++) {
                    int curr = q.front();
                    q.pop();

                    if (curr == b) {
                        found = true;
                        cout << distance << endl;
                        break;
                    }
                    
                    for (int neighbor : graph[curr].neighbors) {
                        if (graph[neighbor].color == 1 && !visited[neighbor]) {
                            q.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }

                if (found) break;

                distance++;
            }

            if (!found) {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}
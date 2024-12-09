#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Router {
    int number;
    vector<int> connections;
};

int bfs(vector<Router>& routers, int source, int destination, int ttl) {
    vector<bool> visited(routers.size(), false);
    queue<pair<int, int>> q;
    q.push({source, ttl});

    while (!q.empty()) {
        int current, current_ttl;
        tie(current, current_ttl) = q.front();
        q.pop();

        if (current == destination) {
            return ttl - current_ttl;
        }

        if (current_ttl == 0) {
            continue;
        }

        visited[current] = true;

        for (int neighbor : routers[current].connections) {
            if (!visited[neighbor]) {
                q.push({neighbor, current_ttl - 1});
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<Router> routers(n + 1);
    for (int i = 1; i <= n; i++) {
        int router, k;
        cin >> router >> k;
        routers[router].number = router;
        
        for (int j = 0; j < k; j++) {
            int connection;
            cin >> connection;
            routers[router].connections.push_back(connection);
        }
    }

    int p;
    cin >> p;

    while (p--) {
        int source, destination, ttl;
        cin >> source >> destination >> ttl;

        int result = bfs(routers, source, destination, ttl);
        if (result == -1) {
            cout << "NA" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
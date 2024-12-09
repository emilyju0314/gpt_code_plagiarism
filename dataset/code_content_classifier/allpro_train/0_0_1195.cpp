#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<int> in_degree(N+1, 0);
    vector<int> next_room(N+1);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        in_degree[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            next_room[i] = 1;
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            in_degree[next]--;
            if (in_degree[next] == 0) {
                q.push(next);
                next_room[next] = curr;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (in_degree[i] > 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 2; i <= N; i++) {
        cout << next_room[i] << endl;
    }

    return 0;
}
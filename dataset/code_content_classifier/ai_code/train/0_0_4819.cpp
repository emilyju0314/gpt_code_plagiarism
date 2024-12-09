#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
int graph[23][23];
bool visited[23];
vector<int> steps;

void make_friends(int u, int v) {
    if (!graph[u][v]) {
        graph[u][v] = graph[v][u] = 1;
        steps.push_back(v);
    }
}

void introduce_friends(int guest) {
    visited[guest] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && i != guest) {
            for (int j = 1; j <= n; j++) {
                if (visited[j] && graph[i][j]) {
                    make_friends(guest, i);
                    break;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    int min_steps = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            introduce_friends(i);
            min_steps++;
        }
    }

    cout << min_steps << endl;
    for (int step : steps) {
        cout << step << " ";
    }

    return 0;
}
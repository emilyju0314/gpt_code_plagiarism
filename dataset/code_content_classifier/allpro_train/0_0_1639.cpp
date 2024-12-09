#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int numCities = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) {
            numCities++;
        }
    }

    int numVillages = N - numCities;

    cout << abs(numCities - numVillages) << endl;

    return 0;
}
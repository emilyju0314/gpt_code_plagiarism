#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Corridor {
    int from, to, energy;
};

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Corridor> corridors(m);
    for (int i = 0; i < m; i++) {
        cin >> corridors[i].from >> corridors[i].to >> corridors[i].energy;
    }

    sort(corridors.begin(), corridors.end(), [](Corridor a, Corridor b){
        return a.energy < b.energy;
    });

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int max_energy = 0;
    for (int i = 0; i < m; i++) {
        int from = corridors[i].from;
        int to = corridors[i].to;
        int energy = corridors[i].energy;

        if (find(from) != find(to)) {
            unite(from, to);
            if (i == 0) {
                max_energy = energy;
            }
        }
    }

    cout << max_energy << endl;

    return 0;
}
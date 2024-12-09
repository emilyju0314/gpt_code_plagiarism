#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct road {
    int u, v, c, idx;
};

vector<road> roads;
vector<int> parent;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        roads.push_back({u, v, c, i + 1});
    }

    sort(roads.begin(), roads.end(), [](const road &a, const road &b){
        return a.c < b.c;
    });

    vector<int> to_reverse;
    int total_controllers = 0;

    for (int i = 0; i < m; i++) {
        if (find(roads[i].u) != find(roads[i].v)) {
            unite(roads[i].u, roads[i].v);
        } else {
            total_controllers += roads[i].c;
            to_reverse.push_back(roads[i].idx);
        }
    }

    cout << total_controllers << " " << to_reverse.size() << endl;
    for (int i : to_reverse) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
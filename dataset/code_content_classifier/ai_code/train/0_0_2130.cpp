#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent, rank_set;
int province_count = 0;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_set[a] < rank_set[b])
            swap(a, b);
        parent[b] = a;
        if (rank_set[a] == rank_set[b])
            rank_set[a]++;
        province_count--;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    parent.resize(n + 1);
    rank_set.resize(n + 1, 0);
    province_count = n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }

    int additional_roads = max(province_count - 1, 0);

    cout << additional_roads << endl;

    return 0;
}
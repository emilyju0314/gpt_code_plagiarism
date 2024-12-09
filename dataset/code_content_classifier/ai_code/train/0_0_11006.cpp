#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m, c, q;
vector<pair<int, int>> roads[100001]; // roads with color as index
unordered_map<int, int> colorIndex; // road color to index map
bool visited[100001];
int parent[100001];
int color[100001];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootX] = rootY;
}

bool canMakeDelivery(int x, int y) {
    int colorX = color[find(x)];
    int colorY = color[find(y)];
    if (colorX != colorY) return false;
    return true;
}

int main() {
    cin >> n >> m >> c >> q;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        roads[z].push_back({x, y});
        colorIndex[z] = i;
    }

    for (int i = 0; i < q; i++) {
        char type;
        int x, y, z;
        cin >> type >> x >> y;
        if (type == '+') {
            cin >> z;
            if (!colorIndex[z]) {
                colorIndex[z] = colorIndex.size();
            }
            roads[z].push_back({x, y});
        } else {
            for (int j = 1; j <= c; j++) {
                for (auto road : roads[j]) {
                    int a = road.first;
                    int b = road.second;
                    if (find(a) != find(b)) {
                        unionSet(a, b);
                        color[parent[a]] = j;
                    }
                }
            }
            if (canMakeDelivery(x, y)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
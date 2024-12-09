#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Vertex {
    int type;
    int transition0;
    int transition1;
};

int getFinalVertex(const vector<Vertex>& vertices, int start, int transition) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (visited.count(current) > 0) continue;
        
        visited.insert(current);
        int next = (transition == 0) ? vertices[current].transition0 : vertices[current].transition1;
        q.push(next);
    }

    return vertices[start].type == vertices[start].type ? vertices[start].type : -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Vertex> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].type >> vertices[i].transition0 >> vertices[i].transition1;
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int type = vertices[q].type;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (vertices[j].type == type) {
                if (getFinalVertex(vertices, q, 0) == getFinalVertex(vertices, j, 0)
                    && getFinalVertex(vertices, q, 1) == getFinalVertex(vertices, j, 1)) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
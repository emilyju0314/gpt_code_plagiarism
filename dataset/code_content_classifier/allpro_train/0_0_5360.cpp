#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int color;
    vector<int> neighbors;
};

void DFS(int node, vector<Node>& tree, vector<bool>& visited, unordered_map<int, int>& colorCount, int& count) {
    visited[node] = true;
    count++;

    for (int neighbor : tree[node].neighbors) {
        if (!visited[neighbor] && tree[neighbor].color == tree[node].color) {
            DFS(neighbor, tree, visited, colorCount, count);
        }
    }
}

int query(int color, vector<Node>& tree, unordered_map<int, int>& colorCount) {
    if (colorCount[color] == 0) {
        return -1;
    }

    vector<bool> visited(tree.size(), false);
    int count = 0;

    for (int i = 1; i < tree.size(); i++) {
        if (!visited[i] && tree[i].color == color) {
            count = 0;
            DFS(i, tree, visited, colorCount, count);
            break;
        }
    }

    return count - 1;
}

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].neighbors.push_back(b);
        tree[b].neighbors.push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> tree[i].color;
    }

    int m;
    cin >> m;

    unordered_map<int, int> colorCount;
    for (int i = 0; i < n; i++) {
        colorCount[tree[i + 1].color]++;
    }

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;

        if (command == 'U') {
            int x, y;
            cin >> x >> y;
            colorCount[tree[x].color]--;
            tree[x].color = y;
            colorCount[y]++;
        } else if (command == 'Q') {
            int color;
            cin >> color;
            int result = query(color, tree, colorCount);
            cout << result << endl;
        }
    }

    return 0;
}
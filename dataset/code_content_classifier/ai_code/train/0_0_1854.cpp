#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& tree, vector<set<int>>& redEdges, vector<set<int>>& blueEdges, vector<int>& blueDeleted, int node, int parent) {
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(tree, redEdges, blueEdges, blueDeleted, child, node);
            if (blueDeleted[node] != -1) {
                blueEdges[node].erase(blueDeleted[node]);
                blueDeleted[node] = -1;
            }
            if (blueEdges[child].size() > 0) {
                blueEdges[node].insert(*blueEdges[child].begin());
            }
            if (redEdges[child].size() > 0) {
                if (blueEdges[node].size() == 1 && *blueEdges[node].begin() == *redEdges[child].begin()) {
                    cout << "Red" << endl;
                    for (int redEdge : redEdges[child]) {
                        cout << redEdge << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    vector<set<int>> redEdges(n + 1);
    vector<set<int>> blueEdges(n + 1);
    vector<int> blueDeleted(n + 1, -1);

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        tree[a].push_back(i);
        blueEdges[i].insert(i - 1);
    }

    for (int i = 2; i <= n; i++) {
        int b;
        cin >> b;
        tree[b].push_back(i);
        redEdges[i].insert(i - 1);
    }

    int idx;
    cin >> idx;

    blueDeleted[1] = idx;
    cout << "Blue" << endl;
    cout << idx << endl;

    dfs(tree, redEdges, blueEdges, blueDeleted, 1, -1);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    vector<int> children;
};

int n, L, S;
vector<Node> tree;
vector<int> weights;

int dfs(int node) {
    if(tree[node].children.empty()) {
        if(weights[node] > S) {
            return -1;
        }
        return 1;
    }

    int paths = 0;
    vector<int> childrenPaths;
    for(int child : tree[node].children) {
        int childPaths = dfs(child);
        if(childPaths == -1) {
            return -1;
        }
        childrenPaths.push_back(childPaths);
    }

    int currentPath = 0;
    for(int childPaths : childrenPaths) {
        if(currentPath + 1 + childPaths > L) {
            paths++;
            currentPath = 0;
        }
        currentPath += 1 + childPaths;
    }

    return paths + 1;
}

int main() {
    cin >> n >> L >> S;
    tree.resize(n + 1);
    weights.resize(n + 1);

    // Reading input
    for(int i = 1; i <= n; i++) {
        cin >> weights[i];
    }

    for(int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].children.push_back(i);
    }

    int result = dfs(1);

    if(result == -1 || result > L) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
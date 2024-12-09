#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> children;
vector<int> rank;
vector<int> manager;
vector<int> replaceability;
vector<int> negligibility;

void dfs(int node) {
    replaceability[node] = 1;
    for (int child : children[node]) {
        dfs(child);
        replaceability[node] += replaceability[child];
    }
}

int main() {
    int n;
    cin >> n;

    children.resize(n);
    rank.resize(n);
    manager.resize(n);
    replaceability.resize(n, 0);
    negligibility.resize(n, 0);

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        children[p].push_back(i);
        manager[i] = p;
    }

    dfs(0);

    for (int i = 1; i < n; i++) {
        int p = manager[i];
        int z = replaceability[i];
        for (int j = p; j != 0; j = manager[j]) {
            if (rank[j] <= rank[i]) {
                z += replaceability[j] - replaceability[i];
            } else {
                break;
            }
        }
        negligibility[i] = z;
    }

    for (int i = 1; i < n; i++) {
        cout << negligibility[i] << " ";
    }
    cout << endl;

    return 0;
}
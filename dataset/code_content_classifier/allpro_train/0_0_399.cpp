#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> removedDistricts;
vector<vector<int>> adjList;
vector<int> fans;
vector<int> subtreeFans;

void dfs(int node, int parent) {
    subtreeFans[node] = fans[node];
    for (int child : adjList[node]) {
        if (child != parent) {
            dfs(child, node);
            subtreeFans[node] += subtreeFans[child];
        }
    }
}

void findDistrictsToRemove(int node, int parent, int removedCount) {
    if (removedCount == 0) {
        return;
    }

    removedDistricts.push_back(node);
    for (int child : adjList[node]) {
        if (child != parent) {
            findDistrictsToRemove(child, node, removedCount - 1);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    adjList.resize(n);
    fans.resize(n);
    subtreeFans.resize(n);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        fans[i] = pow(2, i+1);
    }

    dfs(0, -1);

    vector<pair<int, int>> districtsAndFans;
    for (int i = 0; i < n; i++) {
        districtsAndFans.push_back({i, subtreeFans[i]});
    }

    sort(districtsAndFans.begin(), districtsAndFans.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    findDistrictsToRemove(districtsAndFans[0].first, -1, k);

    sort(removedDistricts.begin(), removedDistricts.end());

    for (int district : removedDistricts) {
        cout << district + 1 << " ";
    }

    return 0;
}
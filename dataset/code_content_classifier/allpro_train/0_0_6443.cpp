#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> size_of_subtree;
int k;
int req_problem_roads = 0;
vector<int> problem_roads;

void dfs(int node, int parent) {
    size_of_subtree[node] = 1;
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node);
            size_of_subtree[node] += size_of_subtree[child];
        }
    }
    if (size_of_subtree[node] == k)
        req_problem_roads = 0;
    else if (size_of_subtree[node] % k == 0)
        req_problem_roads++;
}

void find_problem_roads(int node, int parent) {
    for (int child : graph[node]) {
        if (child != parent) {
            if (size_of_subtree[child] % k == 0) {
                problem_roads.push_back(child);
            }
            find_problem_roads(child, node);
        }
    }
}

int main() {
    int n;
    cin >> n >> k;

    graph.resize(n+1);
    size_of_subtree.resize(n+1);

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, -1);

    cout << req_problem_roads << endl;

    if (req_problem_roads > 0) {
        find_problem_roads(1, -1);
        for (int road : problem_roads) {
            cout << road << " ";
        }
    }

    return 0;
}
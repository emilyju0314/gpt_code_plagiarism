#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        in_degree[b]++;
    }

    int changes = 0;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] > 1) {
            changes++;
        }
    }

    cout << changes << endl;

    return 0;
}
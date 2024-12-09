#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    int max_weight = 0;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        max_weight = max(max_weight, weights[v-1] + weights[u-1] - w);
    }

    cout << max_weight << endl;

    return 0;
}
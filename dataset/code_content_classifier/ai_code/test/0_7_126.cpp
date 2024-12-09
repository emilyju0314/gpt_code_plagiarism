#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    
    vector<int> min_scores(n, INT_MAX);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        min_scores[v] = min(min_scores[v], scores[u] - scores[v] - 1);
    }
    
    for (int i = 0; i < n; i++) {
        scores[i] -= min_scores[i];
    }
    
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    
    return 0;
}
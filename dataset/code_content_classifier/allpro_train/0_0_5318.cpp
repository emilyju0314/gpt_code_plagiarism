#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, p;
        cin >> n >> p;
        
        vector<pair<int, int>> edges;

        // Generate a p-interesting graph
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                edges.push_back({i, j});
            }
        }

        // Print the edges of the graph
        for(int i = 0; i < 2*n+p; i++) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }

    return 0;
}
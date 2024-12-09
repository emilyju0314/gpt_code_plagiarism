#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> fortress(n+1, false);
    for(int i = 0; i < k; i++) {
        int f;
        cin >> f;
        fortress[f] = true;
    }

    vector<set<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int best_strength = 0;
    vector<int> best_set;

    for(int i = 1; i <= n; i++) {
        if(!fortress[i]) {
            set<int> neighbors;
            for(int neighbor : adj[i]) {
                if(!fortress[neighbor]) {
                    neighbors.insert(neighbor);
                }
            }
            if(neighbors.size() > best_strength) {
                best_strength = neighbors.size();
                best_set.clear();
                best_set.push_back(i);
                for(int neighbor : neighbors) {
                    best_set.push_back(neighbor);
                }
            }
        }
    }

    cout << best_strength + 1 << endl;
    for(int city : best_set) {
        cout << city << " ";
    }

    return 0;
}
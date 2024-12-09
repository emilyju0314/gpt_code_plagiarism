#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    
    int changes = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                if(adj[i][j] != 1) {
                    changes++;
                }
            } else {
                if(adj[i][j] == 1 && adj[j][i] == 0) {
                    changes++;
                } else if (adj[i][j] == 0 && adj[j][i] == 1) {
                    changes++;
                }
            }
        }
    }
    
    cout << changes / 2 << endl;
    
    return 0;
}
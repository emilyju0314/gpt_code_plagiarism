#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> c(k);
    for(int i = 0; i < k; i++) {
        cin >> c[i];
    }
    
    vector<vector<int>> d(k, vector<int>(k, INT_MAX));
    for(int i = 0; i < k; i++) {
        d[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        --u;
        --v;
        for(int j = 0; j < k; j++) {
            if(u >= c[j] && v >= c[j]) {
                d[j][j] = 0;
            } else if(u >= c[j]) {
                d[j][v/c[j]] = min(d[j][v/c[j]], x);
            } else if(v >= c[j]) {
                d[u/c[j]][j] = min(d[u/c[j]][j], x);
            } else if(u/c[j] == v/c[j]) {
                d[u/c[j]][v/c[j]] = d[v/c[j]][u/c[j]] = min(d[u/c[j]][v/c[j]], x);
            }
        }
    }
    
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            for(int l = 0; l < k; l++) {
                if(d[j][i] != INT_MAX && d[i][l] != INT_MAX) {
                    d[j][l] = min(d[j][l], d[j][i] + d[i][l]);
                }
            }
        }
    }
    
    bool correct = true;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if(d[i][j] == INT_MAX) {
                correct = false;
                break;
            }
        }
        if(!correct) break;
    }
    
    if(correct) {
        cout << "Yes" << endl;
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(j > 0) cout << " ";
                cout << (d[i][j] == INT_MAX ? -1 : d[i][j]);
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
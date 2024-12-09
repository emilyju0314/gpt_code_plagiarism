#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<pair<int, int>> parts(n);
    
    for (int i = 0; i < n; i++) {
        cin >> parts[i].first >> parts[i].second;
    }
    
    cin >> m;
    vector<vector<int>> actors(m, vector<int>(3));
    
    for (int i = 0; i < m; i++) {
        cin >> actors[i][0] >> actors[i][1] >> actors[i][2];
    }
    
    vector<int> assignment(n, -1);
    bool possible = true;
    
    for (int i = 0; i < n; i++) {
        int aj = parts[i].first;
        int bj = parts[i].second;
        int actor_idx = -1;
        for (int j = 0; j < m; j++) {
            int ci = actors[j][0];
            int di = actors[j][1];
            int ki = actors[j][2];
            if (ki > 0 && ci <= aj && bj <= di) {
                assignment[i] = j + 1;
                actors[j][2]--;
                actor_idx = j;
                break;
            }
        }
        if (actor_idx == -1) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << assignment[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}